#include "src/battle.cpp"
#include "src/data.h"
#include <iostream> 
#include <cassert> 

int main() {
      Trainer t0(100);
      Pokemon p{SpeciesTable::squirtle};
      t0.addMember(p);
      Trainer t1(100);
      t1.addMember(p);
      
      Battle b{t0,t1};
      b.battle();
}
