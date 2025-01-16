#pragma once

#include "../champion.hpp"
#include "../spell.hpp"
#include <algorithm>

// SpellType type, uint16_t range, uint16_t speed, float delay,
// 
// std::map<std::string, std::function<double()>> attributes
class NaafiriSpells : public ChampionSpells {
public:
    NaafiriSpells(
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 50; };

        uint16_t range = 900;
        uint16_t speed = 1700;
        float delay = .25f;

        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        auto packmates = std::min<uint8_t>(std::max<uint8_t>(find_property("packmates"), 0), 3);
        
        uint16_t range = 700 + (80 * packmates);
        return Spell(SpellType::TARGETTED, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 340; };

        uint16_t range = 350;
        uint16_t speed = 900;
        float delay = 0;

        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        uint16_t range = 0;
        return Spell(SpellType::NONE, range);
    }
};