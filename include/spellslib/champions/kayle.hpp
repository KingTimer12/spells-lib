#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float width, float radius, float angle, float delay
class KayleSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 150.f; };
        
        float range = 900.f;
        float speed = 1600.f;
        
        return Spell(SpellType::LINEAR, range, speed, 0, attributes);
    }
    Spell get_w() const override {
        float range = 900.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_e() const override {
        return Spell(SpellType::NONE, 0.f);
    }
    Spell get_r() const override {
        float range = 900.f;
        float delay = .5f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
};