#pragma once

#include <algorithm>

#include "../champion.hpp"
#include "../spell.hpp"


// SpellType type, float range, float speed, float delay, std::map<std::string,
// std::function<float()>> attributes
class VarusSpells : public ChampionSpells {
 private:
  float get_range(const float &timeCast, const float &gameTime,
                  const float &maxRange, const float &minRange) const {
    if (timeCast == 0) return minRange;
    float since_cast = gameTime - timeCast;
    float range =
        since_cast >= .25f
            ? std::min<float>(maxRange,
                              minRange + 70 + (since_cast * 1000) * 0.39)
            : 0;
    return std::max<float>(minRange, range);
  }

 public:
  VarusSpells(std::map<std::string, std::function<float()>> attributes =
                  std::map<std::string, std::function<float()>>())
      : ChampionSpells(attributes) {}

  Spell get_q() const override {
    const auto timeCast = find_property("timecast");
    const auto gameTime = find_property("gametime");
    auto attributes = create_map();
    attributes["width"] = []() { return 140.f; };
    attributes["minRange"] = []() { return 895.f; };
    attributes["maxRange"] = []() { return 1595.f; };

    const float speed = 1900.f;
    const float delay = 0.f;
    const float minRange = find_property_from_map(attributes, "minRange");
    const float maxRange = find_property_from_map(attributes, "maxRange");

    float range = get_range(timeCast, gameTime, maxRange, minRange);
    attributes["eventHorizon"] = [range, minRange]() {
      return std::max<float>(minRange, range - 300);
    };

    return {.attributes = attributes,
            .type = SpellType::LINEAR,
            .range = range,
            .speed = speed,
            .delay = delay};
  }
  Spell get_w() const override { return {}; }
  Spell get_e() const override {
    return {.type = SpellType::CIRCULAR,
            .range = 925.f,
            .delay = .7419f,
            .radius = 300.f};
  }
  Spell get_r() const override {
    // auto attributes = create_map();

    // float range = 1370.f;
    // float speed = 1500.f;
    // float delay = .2419f;
    // attributes["radius"] = []() { return 650.f; };
    // attributes["width"] = []() { return 240.f; };

    return {.type = SpellType::LINEAR,
            .range = 1370.f,
            .speed = 1500.f,
            .delay = .2419f,
            .width = 240.f,
            .radius = 650.f};
  }
};
