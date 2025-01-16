#pragma once

#include "../champion.hpp"
#include "../spell.hpp"
#include <algorithm>

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class VarusSpells : public ChampionSpells {
private:
    int get_range(double &timeCast, double &gameTime, uint16_t &maxRange, uint16_t &minRange) const {
        if (timeCast == 0)
            return maxRange;
        double since_cast = gameTime - timeCast;
        double range = since_cast >= 0.25 ? std::min<double>(maxRange, minRange + 70 + (since_cast * 1000) * 0.39) : 0;
        return std::max<int>(minRange, range);
    }
    
public:
    VarusSpells(
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto timeCast = find_property("timecast");
        auto gameTime = find_property("gametime");
        auto attributes = create_map();
        attributes["width"] = []() { return 140; };
        attributes["minRange"] = []() { return 895; };
        attributes["maxRange"] = []() { return 1595; };
        
        float delay = 0;
        uint16_t maxRange = find_property_from_map(attributes, "maxRange");
        uint16_t minRange = find_property_from_map(attributes, "minRange");
        uint16_t speed = 1900;
        
        uint16_t range = get_range(timeCast, gameTime, maxRange, minRange);
        attributes["eventHorizon"] = [range, minRange]() { return std::max<double>(minRange, range-300); };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        uint16_t range = 0;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 300; };
        
        uint16_t range = 925;
        uint16_t speed = 0;
        double delay = 0.7419;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        
        uint16_t range = 1370;
        uint16_t speed = 1500;
        float delay = .2419f;
        attributes["radius"] = []() { return 650; };
        attributes["width"] = []() { return 240; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};