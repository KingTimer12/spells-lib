#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class AnnieSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        uint16_t range = 625;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["angle"] = []() { return 49.52f; };
        
        uint16_t range = 625;
        uint16_t speed = 1400;
        float delay = .25f;
        
        return Spell(SpellType::CONE, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        uint16_t range = 800;
        return Spell(SpellType::NONE, range);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 250.0f; };
        
        uint16_t range = 600;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, delay, attributes);
    }
};