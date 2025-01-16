#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class GwenSpells : public ChampionSpells {
public:
    GwenSpells(
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        uint16_t range = 625;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        uint16_t range = 430;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 50; };
        
        uint16_t range = 300;
        uint16_t speed = 700;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_r() const override {
        auto timeCast = find_property("timecast");
        auto attributes = create_map();
        
        uint16_t range = 1200;
        uint16_t speed = 1800;
        float delay = timeCast > 1 ? .5f : .25f;
        attributes["width"] = []() { return 120; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};