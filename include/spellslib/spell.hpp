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
    uint16_t range;
    uint16_t speed;
    float delay;
    std::map<std::string, std::function<double()>> attributes;

public:        
    Spell(
        SpellType type,
        uint16_t range,
        uint16_t speed,
        float delay,
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()) : 
        type(type),
        range(range),
        speed(speed),
        delay(delay),
        attributes(attributes) {}
    
    Spell(
        SpellType type, 
        uint16_t range, 
        float delay, 
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()) : 
        type(type),
        range(range),
        speed(0),
        delay(delay),
        attributes(attributes) {}
        
    Spell(
        SpellType type, 
        uint16_t range, 
        std::map<std::string, std::function<double()>> attributes = std::map<std::string, std::function<double()>>()) : 
        type(type),
        range(range),
        speed(0),
        delay(0),
        attributes(attributes) {}
    
    SpellType get_type() const {
        return type;
    }
    
    uint16_t get_range() const {
        return range;
    }
    
    uint16_t get_speed() const {
        return speed;
    }
    
    float get_delay() const {
        return delay;
    }
    
    uint16_t get_width() const {
        return get_property<uint16_t>("width");
    }
    
    uint16_t get_radius() const {
        return get_property<uint16_t>("radius");
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