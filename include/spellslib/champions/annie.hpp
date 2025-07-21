#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class AnnieSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {
        .type = SpellTypeData::TARGETTED,
        .range = 625.f,
        .delay = .25f,
        .damage = [](std::vector<float> args) {
            const float ap = args[1];
            const float level = args[0];
            static constexpr float damage_list[] = {70.f, 105.f, 140.f, 175.f, 210.f};
            return damage_list[static_cast<int>(level) - 1] + (0.75f * ap);
        }
    };
  }
  Spell get_w() const override {
    return {
        .type = SpellTypeData::CONE,
        .range = 625.f,
        .speed = 1400.f,
        .delay = .25f,
        .angle = 49.52f,
        .damage = [](std::vector<float> args) {
            const float ap = args[1];
            const float level = args[0];
            static constexpr float damage_list[] = {70.f, 115.f, 160.f, 205.f, 250.f};
            return damage_list[static_cast<int>(level) - 1] + (0.85f * ap);
        }
    };
  }
  Spell get_e() const override {
    return {
        .type = SpellTypeData::NONE,
        .range = 800.f,
    };
  }
  Spell get_r() const override {
    return {
        .type = SpellTypeData::CIRCULAR,
        .range = 600.f,
        .delay = .25f,
        .radius = 250.f,
        .damage = [](std::vector<float> args) {
            const float ap = args[1];
            const float level = args[0];
            static constexpr float damage_list[] = {150.f, 275.f, 400.f};
            return damage_list[static_cast<int>(level) - 1] + (0.75f * ap);
        }
    };
  }
};
