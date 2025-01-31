#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, float range, float speed, float delay, std::map<std::string, std::function<float()>> attributes
class GnarSpells : public ChampionSpells {
public:
    GnarSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto attributes = create_map();
        auto megaGnar = find_property("gnartransform");
        
        float range = megaGnar ? 1150.f : 1125.f;
        float speed = megaGnar ? 2100.f : 2500.f;
        float delay = megaGnar ? .5f : .25f;
        attributes["width"] = [megaGnar]() { return megaGnar ? 180.f : 110.f; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 200.f; };
        
        float range = 550.f;
        float speed = 0.f;
        float delay = .6f;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto megaGnar = find_property("gnartransform");
        auto attributes = create_map();
        
        float range = megaGnar == 1 ? 675.f : 475.f;
        attributes["radius"] = [megaGnar]() { return megaGnar ? 375.f : 150.f; };
        
        return Spell(SpellType::CIRCULAR, range, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 475.f; };
        
        float range = 475.f;
        
        return Spell(SpellType::LINEAR, range, attributes);
    }
};