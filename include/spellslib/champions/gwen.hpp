#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<float()>> attributes
class GwenSpells : public ChampionSpells {
public:
    GwenSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        return {
            .type = SpellType::TARGETTED,
            .range = 625.f,
            .delay = .25f,
        };
    }
    Spell get_w() const override {
        return {
            .type = SpellType::NONE,
            .range = 430.f,
        };
    }
    Spell get_e() const override {
        return {
            .type = SpellType::LINEAR,
            .range = 300.f,
            .speed = 700.f,
            .delay = 0.f,
            .width = 50.f,
        };
    }
    Spell get_r() const override {
        auto timeCast = find_property("timecast");
        return {
            .type = SpellType::LINEAR,
            .range = 1200.f,
            .speed = 1800.f,
            .delay = timeCast > 1 ? .5f : .25f,
            .width = 120.f,
        };
    }
};