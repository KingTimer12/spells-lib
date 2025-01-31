#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<float()>> attributes
class GwenSpells : public ChampionSpells {
public:
    GwenSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        float range = 625.f;
        float delay = .25f;
        return Spell(SpellType::TARGETTED, range, delay);
    }
    Spell get_w() const override {
        float range = 430.f;
        return Spell(SpellType::NONE, range);
    }
    Spell get_e() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 50.f; };
        
        float range = 300.f;
        float speed = 700.f;
        
        return Spell(SpellType::LINEAR, range, speed, 0.f, attributes);
    }
    Spell get_r() const override {
        auto timeCast = find_property("timecast");
        auto attributes = create_map();
        
        float range = 1200.f;
        float speed = 1800.f;
        float delay = timeCast > 1 ? .5f : .25f;
        attributes["width"] = []() { return 120.f; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
};