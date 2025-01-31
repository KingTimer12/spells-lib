#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<double()>> attributes
class TrundleSpells : public ChampionSpells {
public:
    Spell get_q() const override {
        return Spell(SpellType::NONE, 0.f);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 775.f; };
        
        float range = 750.f;
        float speed = 0.f;
        float delay = 0.f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["radius"] = []() { return 360.f; };
        
        float range = 1000.f;
        float speed = 0.f;
        float delay = .25f;
        
        return Spell(SpellType::CIRCULAR, range, speed, delay, attributes);
    }
    Spell get_r() const override {
        float range = 650.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
};