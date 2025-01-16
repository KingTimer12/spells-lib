#pragma once

#include "../champion.hpp"
#include "../spell.hpp"

// SpellType type, uint16_t range, uint16_t speed, float delay, std::map<std::string, std::function<double()>> attributes
class GnarSpells : public ChampionSpells {
public:
    GnarSpells(
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()
    ) : ChampionSpells(attributes) {}

    Spell get_q() const override {
        auto attributes = create_map();
        auto megaGnar = find_property("gnartransform");
        
        uint16_t range = megaGnar ? 1150 : 1125;
        uint16_t speed = megaGnar ? 2100 : 2500;
        float delay = megaGnar ? .5 : .25;
        attributes["width"] = [megaGnar]() { return megaGnar ? 180 : 110; };
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_w() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 200; };
        
        uint16_t range = 550;
        uint16_t speed = 0;
        float delay = .6f;
        
        return Spell(SpellType::LINEAR, range, speed, delay, attributes);
    }
    Spell get_e() const override {
        auto megaGnar = find_property("gnartransform");
        auto attributes = create_map();
        
        uint16_t range = megaGnar == 1 ? 675 : 475;
        attributes["radius"] = [megaGnar]() { return megaGnar ? 375 : 150; };
        
        return Spell(SpellType::CIRCULAR, range, attributes);
    }
    Spell get_r() const override {
        auto attributes = create_map();
        attributes["width"] = []() { return 475; };
        
        uint16_t range = 475;
        
        return Spell(SpellType::LINEAR, range, attributes);
    }
};