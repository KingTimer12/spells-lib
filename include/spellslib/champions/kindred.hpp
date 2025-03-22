#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string,
// std::function<double()>> attributes
class KindredSpells : public ChampionSpells {
 private:
  float get_range(float mark) const {
    return (float)(500 + (75 * std::min<int>(std::max<int>(0, mark - 3.f), 1) +
                          ((int)((mark - 4.f) / 3.f) * 25.f)));
  }

 public:
  Spell get_q() const override {
    return {.type = SpellType::TARGETTED, .range = 300.f};  // dash range
  }
  Spell get_w() const override {
    return {
        .type = SpellType::CIRCULAR,
        .range = 500.f,
        .speed = 1400.f,
        .radius = 800.f,
    };
  }
  Spell get_e() const override {
    const auto mark = find_property("mark");
    const auto range = get_range(mark);
    return {.type = SpellType::TARGETTED, .range = range, .delay = .25f};
  }
  Spell get_r() const override {
    return {.type = SpellType::NONE, .range = 535.f};
  }
};
