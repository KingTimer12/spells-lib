#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string,
// std::function<double()>> attributes
class JaxSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {.type = SpellType::TARGETTED, .range = 700.f};
  }
  Spell get_w() const override { return {}; }
  Spell get_e() const override {
    return {.type = SpellType::NONE, .range = 375.f};
  }
  Spell get_r() const override {
    return {.type = SpellType::TARGETTED, .range = 600.f, .delay = .25f};
  }
};
