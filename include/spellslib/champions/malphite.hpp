#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellTypeData type, float range, float speed, float delay,
// std::map<std::string, std::function<double()>> attributes
class MalphiteSpells : public ChampionSpells {
 public:
  Spell get_q() const override {
    return {.type = SpellTypeData::TARGETTED,
            .range = 625.f,
            .speed = 1200.f,
            .delay = .25f};
  }
  Spell get_w() const override { return {}; }
  Spell get_e() const override {
    return {.type = SpellTypeData::CIRCULAR,
            .range = 400.f,
            .delay = .2419f,
            .width = 250.f};
  }
  Spell get_r() const override {
    auto attributes = create_map();
    attributes["radius"] = []() { return 300.f; };

    float range = 1000.f;
    float delay = .25f;

    return {
        .type = SpellTypeData::CIRCULAR,
        .range = 1000.f,
        .delay = .25f,
        .radius = 300.f,
    };
  }
};
