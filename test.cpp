#include "src/battle.cpp"
#include <iostream> 
#include <cassert> 

int main() {
      Trainer t0(100);
      Trainer t1(100);
      Pokemon p{SpeciesTable::dragonite};
      t1.addMember(p);
      p.learnMove(MoveTable::tackle);
      p.printMoves();
}

