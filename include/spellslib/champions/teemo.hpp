#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class TeemoSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 680.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        return Spell(SpellType::NONE, 0.f);
    }
    Spell get_e() const override {
        return Spell(SpellType::NONE, 0.f);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 150.f; };
        
        float range = 600.f;
        float speed = 0.f;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
};