#include <gtest/gtest.h>
#include <spellslib/spellslib.hpp>

TEST(SpellsLibrary, get_gnar) {
    SpellsLibrary lib;
    auto gnar = lib.get_gnar(); //mini gnar
    auto q = gnar.get_q();
    
    EXPECT_EQ(q.get_type(), SpellType::LINEAR);
    EXPECT_EQ(q.get_range(), 1125);
    
    gnar = lib.get_gnar(true); //mega gnar
    q = gnar.get_q();
    
    EXPECT_EQ(q.get_type(), SpellType::LINEAR);
    EXPECT_EQ(q.get_range(), 1150);
}