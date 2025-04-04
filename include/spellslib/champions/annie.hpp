#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class AnnieSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    const Spell spell = Spell{
        .type = SpellTypeData::TARGETTED,
        .range = 625.f,
        .delay = .25f,
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
    auto attributes = create_map();
    attributes["radius"] = []() { return 250.0f; };

    float range = 600.f;
    float delay = .25f;

    const Spell spell = Spell{
        .type = SpellTypeData::CIRCULAR,
        .range = 600.f,
        .delay = .25f,
        .radius = 250.f,
    };

    return spell;
  }
};
