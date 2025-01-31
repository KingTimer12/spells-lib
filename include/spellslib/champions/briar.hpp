#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float width, float radius, float angle, float delay
class BriarSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 450.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 60.f; };
        
        float range = 300.f;
        float speed = 1200.f;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 380.f; };
        
        float range = 600.f;
        float speed = 1900.f;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 60.f; };
        
        float range = 10000.f;
        float speed = 2000.f;
        float delay = 1.f;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};