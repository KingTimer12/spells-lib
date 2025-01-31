#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class AnnieSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 625.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["angle"] = []() { return 49.52f; };
        
        float range = 625.f;
        float speed = 1400.f;
        float delay = .25f;
        
        return Spell(SpellType::CONE, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        float range = 800.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 250.0f; };
        
        float range = 600.f;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
};