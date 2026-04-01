#include <gtest/gtest.h>
#include "src/data.h"
#include "src/battle.hpp"

TEST(TSizeTest,BasicAssertions) {
  Trainer t1(100);
  t1.printTeam();
  EXPECT_EQ(t1.team.size(),0);
}

TEST(FaintTest,BasicAssertions) {
  Trainer t2(100);
  for(int i = 0; i < 6; i++){
      t2.team.emplace_back(SpeciesTable::dragonite);
  }
  for(auto& n: t2.team) {
      n.sp.stats[0] = 0;
  }
  EXPECT_EQ(t2.hasFainted(),true);
}
