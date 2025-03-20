#include <gtest/gtest.h>
#include <spellslib/spellslib.hpp>

TEST(SpellsLibrary, get_annie) {
    SpellsLibrary lib;
    auto annie = lib.get_annie();
    auto q = annie.get_q();
    auto w = annie.get_w();
    auto e = annie.get_e();
    auto r = annie.get_r();
    
    EXPECT_EQ(q.type, SpellType::TARGETTED);
    EXPECT_EQ(q.range, 625);
    EXPECT_EQ(w.type, SpellType::CONE);
    EXPECT_EQ(w.range, 625);
    EXPECT_EQ(w.speed, 1400);
    EXPECT_EQ(w.delay, .25f);
    EXPECT_EQ(e.type, SpellType::NONE);
    EXPECT_EQ(e.range, 800);
    EXPECT_EQ(r.type, SpellType::CIRCULAR);
    EXPECT_EQ(r.range, 600);
    EXPECT_EQ(r.delay, .25f);
}

TEST(SpellsLibrary, get_briar) {
    SpellsLibrary lib;
    auto briar = lib.get_briar();
    auto q = briar.get_q();
    auto w = briar.get_w();
    auto e = briar.get_e();
    auto r = briar.get_r();
    
    EXPECT_EQ(q.get_type(), SpellType::TARGETTED);
    EXPECT_EQ(q.get_range(), 450);
    EXPECT_EQ(q.get_delay(), .25f);
    EXPECT_EQ(w.get_type(), SpellType::LINEAR);
    EXPECT_EQ(w.get_range(), 300);
    EXPECT_EQ(w.get_speed(), 1200);
    EXPECT_EQ(e.get_type(), SpellType::LINEAR);
    EXPECT_EQ(e.get_range(), 600);
    EXPECT_EQ(e.get_speed(), 1900);
    EXPECT_EQ(r.get_type(), SpellType::LINEAR);
    EXPECT_EQ(r.get_range(), 10000);
    EXPECT_EQ(r.get_speed(), 2000);
    EXPECT_EQ(r.get_delay(), 1);
}