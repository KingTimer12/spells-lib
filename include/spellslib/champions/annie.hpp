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
    };
  }
  Spell get_w() const override {
    return {
        .type = SpellTypeData::CONE,
        .range = 625.f,
        .speed = 1400.f,
        .delay = .25f,
        .angle = 49.52f,
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
    };
  }
};
