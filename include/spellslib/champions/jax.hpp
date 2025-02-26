#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class JaxSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        float range = 700.f;
        return Spell(SpellType::TARGETTED, range);
    }
    Spell get_w() const override {
        return Spell(SpellType::NONE, 0.f);
    }
    Spell get_e() const override {
        float range = 375.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_r() const override {
        float range = 600.f;
        float delay = .25f;
        return Spell(SpellType::NONE, range, delay);
    }
};