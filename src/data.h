#include "attributes.h"

#ifndef DATA_H
#define DATA_H


namespace SpeciesTable {
  // Species (name,hp,attk,def,speed,SpDef,SpAttk)
   Species bulbasuar{"bulbasaur",45,49,49,45,65,65};
   Species squirtle{"squirtle",44,48,65,43,64,50};
   Species dragonite{"dragonite",91,134,95,80,100,100};
};

namespace MoveTable {
  // Move (name,type,pp,attk,accuracy,special)
   Move tackle{"Tackle",Type::normal,4,4,100};

};

#endif 
