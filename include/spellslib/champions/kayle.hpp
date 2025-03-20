#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float width, float radius, float angle, float delay
class KayleSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        return {
            .type = SpellType::LINEAR,
            .range = 900.f,
            .speed = 1600.f,
            .width = 150.f
        };
    }
    Spell get_w() const override {
        return {
            .type = SpellType::TARGETTED,
            .range = 900.f,
            .delay = .25f
        };
    }
    Spell get_e() const override {
        return {
            .type = SpellType::NONE,
            .range = 525.f
        };
    }
    Spell get_r() const override {
        return {
            .type = SpellType::TARGETTED,
            .range = 900.f,
            .delay = .5f
        };
    }
};