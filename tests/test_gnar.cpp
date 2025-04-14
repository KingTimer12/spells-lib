#include <gtest/gtest.h>

#include <spellslib/spellslib.hpp>

TEST(SpellsLibrary, get_gnar) {
  SpellsLibrary lib;
  auto gnar = lib.get_gnar();  // mini gnar
  gnar.update_attributes("gnartransform", false);
  auto q = gnar.get_q();
  auto e = gnar.get_e();

  EXPECT_EQ(q.type, SpellTypeData::LINEAR);
  EXPECT_EQ(q.range, 1125);
  EXPECT_EQ(e.type, SpellTypeData::CIRCULAR);
  EXPECT_EQ(e.range, 475);

  gnar.update_attributes("gnartransform", true);
  q = gnar.get_q();
  e = gnar.get_e();

  EXPECT_EQ(q.type, SpellTypeData::LINEAR);
  EXPECT_EQ(q.range, 1150);
  EXPECT_EQ(e.type, SpellTypeData::CIRCULAR);
  EXPECT_EQ(e.range, 675);
}
