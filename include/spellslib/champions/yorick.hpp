#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class YorickSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        uint16_t range = 2000;
        return Spell(SpellType::NONE, range);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 225; };
        
        uint16_t range = 600;
        uint16_t speed = 1400;
        float delay = 0;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 200; };
        
        uint16_t range = 700;
        uint16_t speed = 0;
        float delay = .25f;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        return Spell(SpellType::NONE, 0);
    }
};