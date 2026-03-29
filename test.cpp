#include "src/battle.hpp"
#include "src/trainer.hpp"
#include "src/data.h"
#include <iostream> 
#include <cassert> 

int main() {
      Trainer t1(100);
      // No members are in the Trainer before adding them
      assert(t1.team.size() == 0);
      
      
      // Test for check if entire teams hp is equal to zero
      Trainer t2(100);
      for(int i = 0; i < 6; i++){
        t2.team.emplace_back(SpeciesTable::dragonite);
      }
      for(auto& n: t2.team) {
          n.sp.hp = 0;
      }
      assert(t2.hasFainted() == true);
      
      // stab modifer test
      Pokemon d_1{SpeciesTable::dragonite};
      Pokemon d_2{SpeciesTable::dragonite};
      d_1.learnMove(MoveTable::dragon_breath);
      Dmg d{d_1,d_2,d_1.moves[0]};
      assert(d.stab = 2);
}

