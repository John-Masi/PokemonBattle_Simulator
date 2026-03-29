#include "src/battle.cpp"
#include <iostream> 
#include <cassert> 

int main() {
      Trainer t0(100);
      Trainer t1(100);
      Pokemon p{SpeciesTable::squirtle};
      Pokemon p1{SpeciesTable::dragonite};
      t1.addMember(p);
      p1.learnMove(MoveTable::dragon_breath);
      p.level = 5;
      p1.level = 94;

      Dmg d{p1,p,p1.moves[0]};
      std::cout << d.dmg;
      std::cout << d.stab;

      //p.printMoves();
}

