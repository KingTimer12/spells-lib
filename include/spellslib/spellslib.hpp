#pragma once

#include <cstdint>
#include <functional>

#include "champion.hpp"

#include "champions/annie.hpp"
#include "champions/briar.hpp"
#include "champions/gnar.hpp"
#include "champions/gwen.hpp"
#include "champions/malphite.hpp"
#include "champions/naafiri.hpp"
#include "champions/trundle.hpp"
#include "champions/varus.hpp"
#include "champions/yorick.hpp"

class SpellsLibrary {
private:
    static auto create_attributes() {
        return std::map<std::string, std::function<double()>>();
    }

    template<typename T>
    static void update_attributes(ChampionSpells& spells, std::string field, T value) {
        spells.set_attribute(field, [value]() { return value; });
    }
    
public:
    const AnnieSpells& get_annie() const {
        static AnnieSpells spells;
        return spells;
    }
    const BriarSpells& get_briar() const {
        static BriarSpells spells;
        return spells;
    }
    const MalphiteSpells& get_malphite() const {
        static MalphiteSpells spells;
        return spells;
    }
    const TrundleSpells& get_trundle() const {
        static TrundleSpells spells;
        return spells;
    }
    const YorickSpells& get_yorick() const {
        static YorickSpells spells;
        return spells;
    }
    
    const NaafiriSpells& get_naafiri(const uint8_t packmates = 0) const {
        static NaafiriSpells spells = []() {
            auto attributes = create_attributes();
            return NaafiriSpells(attributes);
        }();
        update_attributes(spells, "packmates", packmates);
        return spells;
    }
    const GnarSpells& get_gnar(const bool mega_gnar = false) const {
        static GnarSpells spells = []() {
            auto attributes = create_attributes();
            return GnarSpells(attributes);
        }();
        update_attributes(spells, "gnartransform", mega_gnar);
        return spells;
    }
    const GwenSpells& get_gwen(const double timeCast = 0) const {
        static GwenSpells spells = []() {
            auto attributes = create_attributes();
            return GwenSpells(attributes);
        }();
        update_attributes(spells, "timecast", timeCast);
        return spells;
    }
    const VarusSpells& get_varus(const double timeCast = 0, const double gameTime = 0) const {
        static VarusSpells spells = []() {
            auto attributes = create_attributes();
            return VarusSpells(attributes);
        }();
        if (spells.find_property("timecast") == 0)
            update_attributes(spells, "timecast", timeCast);
        update_attributes(spells, "gametime", gameTime);
        return spells;
    }
};