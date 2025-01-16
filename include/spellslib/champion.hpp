#pragma once
#include "spell.hpp"

#include <functional>
#include <map>
#include <string>

class ChampionSpells {
private:
    std::map<std::string, std::function<double()>> attributes;
    
protected:
    auto create_map() const {
        return std::map<std::string, std::function<double()>>();
    }
    
    double find_property_from_map(const std::map<std::string, std::function<double()>> &map, const std::string& property_name) const {
        auto it = map.find(property_name);
        if (it != map.end())
            return it->second();
        return 0;
    }

public:
    ChampionSpells(
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()
    ) : attributes(attributes) {}
    virtual ~ChampionSpells() = default;
    
    virtual Spell get_q() const = 0;
    virtual Spell get_w() const = 0;
    virtual Spell get_e() const = 0;
    virtual Spell get_r() const = 0;
    
    void set_attribute(std::string field, std::function<double()> value) {
        this->attributes[field] = value;
    }
    
    double find_property(const std::string& property_name) const {
        return find_property_from_map(this->attributes, property_name);
    }
    
    void reset_attribute(const std::string& field) {
        this->attributes[field] = []() -> double { return 0; };
    }
    
    void reset_attributes() {
        for(auto& pair : this->attributes)
            pair.second = []() -> double { return 0; };
    }
};