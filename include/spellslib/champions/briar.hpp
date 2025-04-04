#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float width, float radius,
// float angle, float delay
class BriarSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {.type = SpellTypeData::TARGETTED, .range = 450.f, .delay = .25f};
  }
  Spell get_w() const override {
    return {
        .type = SpellTypeData::LINEAR,
        .range = 300.f,
        .speed = 1200.f,
        .width = 60.f,
    };
  }
  Spell get_e() const override {
    return {
        .type = SpellTypeData::LINEAR,
        .range = 600.f,
        .speed = 1900.f,
        .width = 380.f,
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
