#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class TrundleSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        return Spell(SpellType::NONE, 0);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 775; };
        
        uint16_t range = 750;
        uint16_t speed = 0;
        float delay = 0;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 360; };
        
        uint16_t range = 1000;
        uint16_t speed = 0;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        uint16_t range = 650;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
};