#include "attributes.h"

#ifndef DATA_H
#define DATA_H

namespace SpeciesTable {
  // Species (attk,def,speed,SpDef,SpAttk)
  constexpr static Species bulbasuar{49,49,45,65,65,Type::grass,Type::poison};
  constexpr static Species ivysaur{62,63,60,80,80,Type::grass,Type::poison};
  constexpr static Species venasaur{82,83,80,100,100,Type::grass,Type::poison};
  constexpr static Species squirtle{48,65,43,64,50,Type::water};
  constexpr static Species wartortle{63,80,58,80,65,Type::water};
  constexpr static Species blastoise{83,100,78,105,85,Type::water};
  constexpr static Species charmander{52,43,65,50,60,Type::fire};
  constexpr static Species charmeleon{64,58,80,65,80,Type::fire};
  constexpr static Species charizard{84,78,100,85,109,Type::fire,Type::flying};
  constexpr static Species caterpie{30,35,45,20,20,Type::bug};
  constexpr static Species metapod{20,55,30,25,25,Type::bug};
  constexpr static Species butterfree{45,50,70,80,90,Type::bug,Type::flying};
  constexpr static Species dragonite{134,95,80,100,100,Type::dragon,Type::flying,NatureTable::hardy};
};

namespace MoveTable {
  // Move (name,type,pp,attk,accuracy,special)
  static Move tackle{"Tackle",Type::normal,4,40,100};
  static Move dragon_breath{"Dragon Breath",Type::dragon,20,60,100};

};

#endif 
