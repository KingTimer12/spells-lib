#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class MalphiteSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 625.f;
        float speed = 1200.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, speed, delay);
    }
    Spell get_w() const override {
        float range = 0.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 250.f; };
        float range = 400.f;
        float delay = .2419f;
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 300.f; };
        
        float range = 1000.f;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
};