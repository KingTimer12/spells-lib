#pragma once

#include <algorithm>

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
//
// std::map<std::string, std::function<float()>> attributes
class NaafiriSpells : public ChampionSpells {
 public:
  NaafiriSpells(std::map<std::string, std::function<float()>> attributes =
                    std::map<std::string, std::function<float()>>())
      : ChampionSpells(attributes) {}

  Spell get_q() const override {
    return {.type = SpellTypeData::LINEAR,
            .range = 900.f,
            .speed = 1700.f,
            .delay = .25f,
            .width = 50.f};
  }
  Spell get_w() const override {
    const auto packmates =
        std::min<uint8_t>(std::max<uint8_t>(find_property("packmates"), 0), 3);

    return {
        .type = SpellTypeData::TARGETTED,
        .range = (float)(700 + (80 * packmates)),
    };
  }
  Spell get_e() const override {
    return {
        .type = SpellTypeData::CIRCULAR,
        .range = 350.f,
        .speed = 900.f,
        .delay = .0f,
        .radius = 340.f,
    };
  }
  Spell get_r() const override { return {}; }
};
