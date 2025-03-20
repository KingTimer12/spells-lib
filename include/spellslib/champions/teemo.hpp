#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class TeemoSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        return {
            .type = SpellType::TARGETTED,
            .range = 680.f,
            .delay = .25f,
        };
    }
    Spell get_w() const override {
        return {};
    }
    Spell get_e() const override {
        return {};
    }
    Spell get_r() const override {
        return {
            .type = SpellType::CIRCULAR,
            .range = 600.f,
            .speed = 0.f,
            .delay = .25f,
            .radius = 105.f
        };
    }
};