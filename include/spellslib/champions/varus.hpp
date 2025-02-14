#pragma once

#include "../champion.hpp"
#include "../spell.hpp"
#include <algorithm>

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<float()>> attributes
class VarusSpells : public ChampionSpells {
private:
    float get_range(float &timeCast, float &gameTime, float &maxRange, float &minRange) const {
        if (timeCast == 0)
            return minRange;
        float since_cast = gameTime - timeCast;
        float range = since_cast >= .25f ? std::min<float>(maxRange, minRange + 70 + (since_cast * 1000) * 0.39) : 0;
        return std::max<float>(minRange, range);
    }
    
public:
    VarusSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto timeCast = find_property("timecast");
        auto gameTime = find_property("gametime");
        auto attributes = create_map();
        attributes["width"] = []() { return 140.f; };
        attributes["minRange"] = []() { return 895.f; };
        attributes["maxRange"] = []() { return 1595.f; };
        
        float delay = 0.f;
        float maxRange = find_property_from_map(attributes, "maxRange");
        float minRange = find_property_from_map(attributes, "minRange");
        float speed = 1900.f;
        
        float range = get_range(timeCast, gameTime, maxRange, minRange);
        attributes["eventHorizon"] = [range, minRange]() { return std::max<float>(minRange, range-300); };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        float range = 0.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 300.f; };
        
        float range = 925.f;
        float speed = 0.f;
        float delay = .7419f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        
        float range = 1370.f;
        float speed = 1500.f;
        float delay = .2419f;
        attributes["radius"] = []() { return 650.f; };
        attributes["width"] = []() { return 240.f; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};