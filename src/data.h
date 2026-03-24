#include "attributes.h"

#ifndef DATA_H
#define DATA_H


namespace SpeciesTable {
  // Species (name,hp,attk,def,speed,SpDef,SpAttk)
  Species bulbasuar{"bulbasaur",45,49,49,45,65,65};
  Species ivysaur{"ivysaur",60,62,63,60,80,80};
  Species venasaur{"venasaur",80,82,83,80,100,100};
  Species squirtle{"squirtle",44,48,65,43,64,50};
  Species wartortle{"wartortle",59,63,80,58,80,65};
  Species blastoise{"blastoise",79,83,100,78,105,85};
  Species charmander{"charmander",39,52,43,65,50,60};
  Species charmeleon{"charmeleon",58,64,58,80,65,80};
  Species charizard{"charizard",78,84,78,100,85,109};
  Species caterpie{"caterpie",45,30,35,45,20,20};
  Species metapod{"metapod",50,20,55,30,25,25};
  Species butterfree{"butterfree",60,45,50,70,80,90};
  Species dragonite{"dragonite",91,134,95,80,100,100};
};

namespace MoveTable {
  // Move (name,type,pp,attk,accuracy,special)
  Move tackle{"Tackle",Type::normal,4,4,100};
  Move tackle{"Tackle",Type::normal,4,4,100};
  Move tackle{"Tackle",Type::normal,4,4,100};

};

#endif 
