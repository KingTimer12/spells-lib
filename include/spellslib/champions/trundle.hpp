#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class TrundleSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        return{};
    }
    Spell get_w() const override {
        return {
            .type = SpellType::CIRCULAR,
            .range = 750.f,
            .speed = 0.f,
            .delay = 0.f,
            .radius = 775.f
        };
    }
    Spell get_e() const override {
        return{
            .type = SpellType::CIRCULAR,
            .range = 1000.f,
            .speed = 0.f,
            .delay = .25f,
            .radius = 360.f
        };
    }
    Spell get_r() const override {
        return {
            .type = SpellType::CIRCULAR,
            .range = 650.f,
            .delay = .25f,
        };
    }
};