#pragma once

#include <functional>

#include "champions/annie.hpp"
#include "champions/briar.hpp"
#include "champions/gnar.hpp"
#include "champions/gwen.hpp"
#include "champions/kayle.hpp"
#include "champions/malphite.hpp"
#include "champions/naafiri.hpp"
#include "champions/trundle.hpp"
#include "champions/varus.hpp"
#include "champions/yorick.hpp"
#include "champions/teemo.hpp"
#include "champions/jax.hpp"

class SpellsLibrary
{
private:
    static auto create_attributes()
    {
        return std::map<std::string, std::function<float()>>();
    }

public:
    const AnnieSpells &get_annie() const
    {
        static AnnieSpells spells;
        return spells;
    }
    const JaxSpells &get_jax() const
    {
        static JaxSpells spells;
        return spells;
    }
    const BriarSpells &get_briar() const
    {
        static BriarSpells spells;
        return spells;
    }
    const MalphiteSpells &get_malphite() const
    {
        static MalphiteSpells spells;
        return spells;
    }
    const TrundleSpells &get_trundle() const
    {
        static TrundleSpells spells;
        return spells;
    }
    const YorickSpells &get_yorick() const
    {
        static YorickSpells spells;
        return spells;
    }
    const TeemoSpells &get_teemo() const
    {
        static TeemoSpells spells;
        return spells;
    }
    const KayleSpells &get_kayle() const
    {
        static KayleSpells spells;
        return spells;
    }

    const NaafiriSpells &get_naafiri() const
    {
        static NaafiriSpells spells = []()
        {
            auto attributes = create_attributes();
            return NaafiriSpells(attributes);
        }();
        // update_attributes(spells, "packmates", packmates);
        return spells;
    }
    const GnarSpells &get_gnar() const
    {
        static GnarSpells spells = []()
        {
            auto attributes = create_attributes();
            return GnarSpells(attributes);
        }();
        // update_attributes(spells, "gnartransform", mega_gnar);
        return spells;
    }
    const GwenSpells &get_gwen() const
    {
        static GwenSpells spells = []()
        {
            auto attributes = create_attributes();
            return GwenSpells(attributes);
        }();
        // update_attributes(spells, "timecast", timeCast);
        return spells;
    }
    const VarusSpells &get_varus() const
    {
        static VarusSpells spells = []()
        {
            auto attributes = create_attributes();
            return VarusSpells(attributes);
        }();
        // if (spells.find_property("timecast") == 0)
        //     update_attributes(spells, "timecast", timeCast);
        // update_attributes(spells, "gametime", gameTime);
        return spells;
    }
};