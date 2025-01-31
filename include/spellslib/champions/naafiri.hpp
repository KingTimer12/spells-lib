#pragma once

#include "../champion.hpp"
#include "../spell.hpp"
#include <algorithm>

// SpellType type, float range, float speed, float delay,
// 
// std::map<std::string, std::function<float()>> attributes
class NaafiriSpells : public ChampionSpells {
public:
    NaafiriSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 50.f; };

        float range = 900.f;
        float speed = 1700.f;
        float delay = .25f;

        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        auto packmates = std::min<uint8_t>(std::max<uint8_t>(find_property("packmates"), 0), 3);
        
        float range = (float)(700 + (80 * packmates));
        return Spell(SpellType::TARGETTED, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 340.f; };

        float range = 350.f;
        float speed = 900.f;
        float delay = 0.f;

        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        float range = 0.f;
        return Spell(SpellType::NONE, range);
    }
};