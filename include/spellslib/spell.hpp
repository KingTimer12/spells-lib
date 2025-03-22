#pragma once

#include <cfloat>
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
 public:
  std::map<std::string, std::function<float()>> attributes;

  SpellType type = SpellType::NONE;
  float range = FLT_MAX;
  float speed = FLT_MAX;
  float delay = .0f;
  float width = .0f;
  float radius = .0f;
  float angle = .0f;

  template <typename T>
  T get_property(const std::string& property_name) const {
    const auto it = this->attributes.find(property_name);
    if (it != this->attributes.end()) return (T)it->second();
    return 0;
  }
};
