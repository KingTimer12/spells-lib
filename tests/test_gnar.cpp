#include <gtest/gtest.h>
#include <spellslib/spellslib.hpp>

TEST(SpellsLibrary, get_gnar) {
    SpellsLibrary lib;
    auto gnar = lib.get_gnar(); //mini gnar
    gnar.update_attributes("gnartransform", false);
    auto q = gnar.get_q();
    
    EXPECT_EQ(q.get_type(), SpellType::LINEAR);
    EXPECT_EQ(q.get_range(), 1125);

    gnar.update_attributes("gnartransform", true);
    q = gnar.get_q();
    
    EXPECT_EQ(q.get_type(), SpellType::LINEAR);
    EXPECT_EQ(q.get_range(), 1150);
}