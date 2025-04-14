#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class OriannaSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
      return {
          .type = SpellTypeData::LINEAR,
          .range = 825.f,
          .speed = 1400.f,
          .width = 160.f,
      };
  }
  Spell get_w() const override {
      return {
          .type = SpellTypeData::NONE,
          .radius = 225.f,
      };
  }
  Spell get_e() const override {
      return {
          .type = SpellTypeData::NONE,
          .range = 1120.f,
      };
  }
  Spell get_r() const override {
    return {
        .type = SpellTypeData::NONE,
        .delay = .5f,
        .radius = 415.f
    };
  }
};
