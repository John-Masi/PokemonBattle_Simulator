#include <gtest/gtest.h>
#include "include/data.h"
#include "include/team.h"
#include "src/trainer.hpp"

TEST(AttkScoreTest,BasicAssertions) {
  Team team;

  team.addMember("Dragonite",SpeciesTable::dragonite);
  team.team[0]->learnAttk(MoveTable::tackle);

  Trainer trainer{team};
  //std::cout << trainer.scoreATTK(trainer.team.team[0]->moves[0],trainer.team.team[0]);
}

TEST(ShouldSwapTest,BasicAssertions) {
  auto squirtle = std::make_shared<Pokemon>("squirtle",SpeciesTable::squirtle);
  Team team;
  team.addMember("Charmander",SpeciesTable::charmander);
  Trainer t1{team};

  EXPECT_EQ(t1.shouldSwap(squirtle),true);
}

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
