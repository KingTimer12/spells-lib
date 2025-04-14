#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class OriannaSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    const Spell spell = Spell{
        .type = SpellTypeData::LINEAR,
        .range = 825.f,
        .speed = 1400.f,
        .width = 160.f,
    };
    return spell;
  }
  Spell get_w() const override {
    const Spell spell = Spell{
        .type = SpellTypeData::CONE,
        .range = 625.f,
        .speed = 1400.f,
        .delay = .25f,
        .angle = 49.52f,
    };

    return spell;
  }
  Spell get_e() const override {
    const Spell spell = Spell{
        .type = SpellTypeData::NONE,
        .range = 800.f,
    };
    return spell;
  }
  Spell get_r() const override {
    return {.type = SpellTypeData::NONE,
        .delay = .5f,
        .radius = 415.f};
    };

    return spell;
  }
};
