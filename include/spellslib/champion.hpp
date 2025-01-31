#pragma once
#include "spell.hpp"

#include <functional>
#include <map>
#include <string>

class ChampionSpells {
private:
    std::map<std::string, std::function<float()>> attributes;
    
protected:
    auto create_map() const {
        return std::map<std::string, std::function<float()>>();
    }
    
    float find_property_from_map(const std::map<std::string, std::function<float()>> &map, const std::string& property_name) const {
        auto it = map.find(property_name);
        if (it != map.end())
            return it->second();
        return 0.0f;
    }

public:
    ChampionSpells(
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()
    ) : attributes(attributes) {}
    virtual ~ChampionSpells() = default;
    
    virtual Spell get_q() const = 0;
    virtual Spell get_w() const = 0;
    virtual Spell get_e() const = 0;
    virtual Spell get_r() const = 0;
    
    void set_attribute(std::string field, std::function<float()> value) {
        this->attributes[field] = value;
    }
    
    float find_property(const std::string& property_name) const {
        return find_property_from_map(this->attributes, property_name);
    }
    
    void reset_attribute(const std::string& field) {
        this->attributes[field] = []() -> float { return 0.0f; };
    }
    
    void reset_attributes() {
        for(auto& pair : this->attributes)
            pair.second = []() -> float { return 0.0f; };
    }
};