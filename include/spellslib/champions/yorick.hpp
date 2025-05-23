#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class YorickSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {.type = SpellTypeData::NONE, .range = 2000.f};
  }
  Spell get_w() const override {
    return {.type = SpellTypeData::CIRCULAR,
            .range = 600.f,
            .speed = 1400.f,
            .delay = .0f,
            .radius = 225.f};
  }
  Spell get_e() const override {
    return {.type = SpellTypeData::LINEAR,
            .range = 700.f,
            .speed = .0f,
            .delay = .25f,
            .width = 200.f};
  }
  Spell get_r() const override { return {}; }
};
