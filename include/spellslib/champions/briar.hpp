#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float width, float radius,
// float angle, float delay
class BriarSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {
        .type = SpellTypeData::TARGETTED,
        .range = 450.f,
        .delay = .25f,
        .damage = [](std::vector<float> args) {
            const float level = args[0];
            const float ap = args[1];
            const float ad_bonus = args[2];
            static constexpr float damage_list[] = {60.f, 90.f, 120.f, 150.f, 180.f};
            return damage_list[static_cast<int>(level) - 1] + (.6f * ap) + (.8f * ad_bonus);
        }
    };
  }
  Spell get_w() const override {
    return {
        .type = SpellTypeData::LINEAR,
        .range = 300.f,
        .speed = 1200.f,
        .width = 60.f,
        .damage = [](std::vector<float> args) {
            const float level = args[0];
            const float ad = args[1];
            const float ad_bonus = args[2];
            const float target_miss_hp = args[3];
            const float missing_health_percent = 9.f + (2.5f * ad_bonus / 100.f);
            static constexpr float damage_list[] = {5.f, 20.f, 35.f, 50.f, 65.f};
            return damage_list[static_cast<int>(level) - 1] + (0.05f * ad) + (missing_health_percent * 0.01f * target_miss_hp);
        }
    };
  }
  Spell get_e() const override {
    return {
        .type = SpellTypeData::LINEAR,
        .range = 600.f,
        .speed = 1900.f,
        .width = 380.f,
        .damage = [](std::vector<float> args) {
            const float level = args[0];
            const float ap = args[1];
            const float ad_bonus = args[2];
            static constexpr float damage_list[] = {80.f, 115.f, 150.f, 185.f, 220.f};
            return damage_list[static_cast<int>(level) - 1] + (1.f * ad_bonus) + (1.f * ap);
        }
    };
  }
  Spell get_r() const override {
    return {
        .type = SpellTypeData::LINEAR,
        .range = 10000.f,
        .speed = 2000.f,
        .delay = 1.f,
        .width = 60.f,
    };
  }
};
