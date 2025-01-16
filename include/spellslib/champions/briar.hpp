#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, uint16_t width, uint16_t radius, float angle, float delay
class BriarSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        uint16_t range = 450;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 60.f; };
        
        uint16_t range = 300;
        uint16_t speed = 1200;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 380.f; };
        
        uint16_t range = 600;
        uint16_t speed = 1900;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 60.f; };
        
        uint16_t range = 10000;
        uint16_t speed = 2000;
        float delay = 1;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};