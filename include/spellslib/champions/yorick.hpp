#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class YorickSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 2000.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 225.f; };
        
        float range = 600.f;
        float speed = 1400.f;
        float delay = 0.f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 200.f; };
        
        float range = 700.f;
        float speed = 0.f;
        float delay = .25f;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        return Spell(SpellType::NONE, 0.f);
    }
};