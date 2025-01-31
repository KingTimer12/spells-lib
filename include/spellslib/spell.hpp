#pragma once
#include <cstdint>
#include <functional>
#include <map>
#include <string>

enum class SpellType {
    CONE,
    CIRCULAR,
    LINEAR,
    TARGETTED,
    NONE,
};

class Spell {
private:
    SpellType type;
    float range;
    float speed;
    float delay;
    std::map<std::string, std::function<float()>> attributes;

public:        
    Spell(
        SpellType type,
        float range,
        float speed,
        float delay,
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()) : 
        type(type),
        range(range),
        speed(speed),
        delay(delay),
        attributes(attributes) {}
    
    Spell(
        SpellType type, 
        float range, 
        float delay, 
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()) : 
        type(type),
        range(range),
        speed(0),
        delay(delay),
        attributes(attributes) {}
        
    Spell(
        SpellType type, 
        float range, 
        std::map<std::string, std::function<float()>> attributes = std::map<std::string, std::function<float()>>()) : 
        type(type),
        range(range),
        speed(0),
        delay(0),
        attributes(attributes) {}
    
    SpellType get_type() const {
        return type;
    }
    
    float get_range() const {
        return range;
    }
    
    float get_speed() const {
        return speed;
    }
    
    float get_delay() const {
        return delay;
    }
    
    float get_width() const {
        return get_property<float>("width");
    }
    
    float get_radius() const {
        return get_property<float>("radius");
    }
    
    float get_angle() const {
        return get_property<float>("angle");
    }
    
    template<typename T>
    T get_property(const std::string& property_name) const {
        auto it = this->attributes.find(property_name);
        if (it != this->attributes.end())
            return (T)it->second();
        return 0;
    }
    
};