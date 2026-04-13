#include <iostream> 
#include "src/battle.hpp"
#include "include/data.h"

int main() {
  Pokemon charman{"name",SpeciesTable::charmander};

  charman.learnAttk(MoveTable::tackle);
  charman.learnEffect(EffectTable::p_effect);
  charman.printMoves();
}
