#include <gtest/gtest.h>
#include "include/data.h"
#include "include/team.h"

TEST(MoveEffectContainer,BasicAssertions) {
  Pokemon charman{"Charmander",SpeciesTable::charmander};
  charman.learnAttk(MoveTable::tackle);
  charman.learnAttk(MoveTable::tackle);
  charman.learnEffect(EffectTable::p_effect);

  EXPECT_EQ(charman.moves.size(),3);
}

// Tests for team struct 
TEST(FaintTest,BasicAssertions) {
  Team t;
  t.addMember("TestMon_1",SpeciesTable::dragonite);
  t.addMember("TestMon_2",SpeciesTable::dragonite);
  t.addMember("TestMon_3",SpeciesTable::dragonite);
  t.addMember("TestMon_4",SpeciesTable::dragonite);
  t.addMember("TestMon_5",SpeciesTable::dragonite);
  t.addMember("TestMon_6",SpeciesTable::dragonite);

  for(auto& n: t.team) {
    n->hp = 0;
  }

  EXPECT_EQ(t.teamFainted(),true);
}

TEST(AddMember,BasicAssertions) {
  Team t0;
  t0.addMember("TestMon_7",SpeciesTable::dragonite);
  EXPECT_EQ(t0.team.size(),1);

}
