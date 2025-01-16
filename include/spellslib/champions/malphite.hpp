#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class MalphiteSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        uint16_t range = 625;
        uint16_t speed = 1200;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, speed, delay);
    }
    Spell get_w() const override {
        uint16_t range = 0;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 250.0f; };
        uint16_t range = 400;
        float delay = .2419f;
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 300.0f; };
        
        uint16_t range = 1000;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
};