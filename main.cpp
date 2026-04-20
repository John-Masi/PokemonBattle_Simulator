#include <iostream> 
#include "src/battle.hpp"
#include "include/data.h"

int main() {
  auto charmander = std::make_shared<Pokemon>("Charmander",SpeciesTable::charmander);

  Team team;

  team.addMember("Dragonite",SpeciesTable::dragonite);
  team.team[0]->learnAttk(MoveTable::tackle);

  Trainer trainer{team};
  trainer.scoreATTK(charmander);
}
