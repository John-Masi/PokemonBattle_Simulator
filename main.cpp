#include <iostream> 
#include "src/data.h"
#include "src/battle.hpp"
#include <cassert> 

int main() {
  Trainer t1{100};
  Pokemon p{SpeciesTable::dragonite};
  t1.addMember(p);
  t1.printTeam();

}
