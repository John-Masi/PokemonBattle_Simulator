#include "attributes.h"

#ifndef DATA_H
#define DATA_H


namespace SpeciesTable {
  // Species (name,hp,attk,def,speed,SpDef,SpAttk)
  static Species bulbasuar{"bulbasaur",45,49,49,45,65,65,Type::grass,Type::poison};
  static Species ivysaur{"ivysaur",60,62,63,60,80,80,Type::grass,Type::poison};
  static Species venasaur{"venasaur",80,82,83,80,100,100,Type::grass,Type::poison};
  static Species squirtle{"squirtle",44,48,65,43,64,50,Type::water};
  static Species wartortle{"wartortle",59,63,80,58,80,65,Type::water};
  static Species blastoise{"blastoise",79,83,100,78,105,85,Type::water};
  static Species charmander{"charmander",39,52,43,65,50,60,Type::fire};
  static Species charmeleon{"charmeleon",58,64,58,80,65,80,Type::fire};
  static Species charizard{"charizard",78,84,78,100,85,109,Type::fire,Type::flying};
  static Species caterpie{"caterpie",45,30,35,45,20,20,Type::bug};
  static Species metapod{"metapod",50,20,55,30,25,25,Type::bug};
  static Species butterfree{"butterfree",60,45,50,70,80,90,Type::bug,Type::flying};
  static Species dragonite{"dragonite",91,134,95,80,100,100,Type::dragon,Type::flying};
};

namespace MoveTable {
  // Move (name,type,pp,attk,accuracy,special)
  static Move tackle{"Tackle",Type::normal,4,40,100};
  static Move dragon_breath{"Dragon Breath",Type::dragon,20,60,100};

};

#endif 
