#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<float()>> attributes
class GnarSpells : public ChampionSpells {
public:
    GnarSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto megaGnar = find_property("gnartransform");

        return {
            .type = SpellType::LINEAR,
            .range = megaGnar ? 1150.f : 1125.f,
            .speed = megaGnar ? 2100.f : 2500.f,
            .delay = megaGnar ? .5f : .25f,
            .width = megaGnar ? 180.f : 110.f,
        };
    }
    Spell get_w() const override {
        return {
            .type = SpellType::LINEAR,
            .range = 550.f,
            .speed = 0.f,
            .delay = .6f,
            .width = 200.f,
        };
    }
    Spell get_e() const override {
        auto megaGnar = find_property("gnartransform");
        return {
            .type = SpellType::CIRCULAR,
            .range = megaGnar ? 675.f : 475.f,
            .radius = megaGnar ? 375.f : 150.f,
        };
    }
    Spell get_r() const override {

        return {
            .type = SpellType::LINEAR,
            .range = 475.f,
            .width = 475.f,
        };
    }
};