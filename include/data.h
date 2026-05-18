#include "attributes.h"

#ifndef DATA_H
#define DATA_H

namespace SpeciesTable {
  // Species (attk,def,speed,SpDef,SpAttk)
  Species bulbasuar{49,49,45,65,65,Type::grass,Type::poison};
  Species ivysaur{62,63,60,80,80,Type::grass,Type::poison};
  Species venasaur{82,83,80,100,100,Type::grass,Type::poison};
  Species squirtle{48,65,43,64,50,Type::water};
  Species wartortle{63,80,58,80,65,Type::water};
  Species blastoise{83,100,78,105,85,Type::water};
  Species charmander{52,43,65,50,60,Type::fire};
  Species charmeleon{64,58,80,65,80,Type::fire};
  Species charizard{84,78,100,85,109,Type::fire,Type::flying};
  Species caterpie{30,35,45,20,20,Type::bug};
  Species metapod{20,55,30,25,25,Type::bug};
  Species butterfree{45,50,70,80,90,Type::bug,Type::flying};
  Species weedle{40,35,50,20,20,Type::bug,Type::poison};
  Species kakuna{25,50,35,25,25,Type::bug,Type::poison};
  Species beedrill{90,40,75,80,45,Type::bug,Type::poison};
  Species pidgey{45,40,56,35,35,Type::flying};
  Species pidgeotto{60,55,71,50,50,Type::flying};
  Species pidgeot{80,75,101,70,70,Type::flying};

  Species arcanine{110,80,95,80,100,Type::fire};
  Species weezing{90,120,60,70,85,Type::poison};
  Species raichu{90,55,110,80,90,Type::electric};
  Species blaziken{70,120,80,70,110,Type::fire,Type::fighting};
  Species ditto{48,48,48,48,48,Type::normal};
  Species articuno{85,100,85,125,85,Type::flying,Type::ice};

  Species moltress{100,90,90,85,125,Type::fire,Type::flying};
  Species dragonite{134,95,80,100,100,Type::dragon,Type::flying};

};

namespace EffectFunctions {
  void protect() {

  }

  void trick_room() {

  }
  
  // Buff pokemons attack stat
  void sword_dance(Pokemon& p,int count = 0) {
    if(count <= 2) {
        p.sp.stats[0] += 2;
    }
    else{
      std::cout << "Cannont buff attack anymore";
    }
  }
};

namespace EffectTable {
  Effect p_effect{EffectFunctions::protect,"protect",0,0};
};

namespace MoveTable {
  // Move (name,type,pp,attk,accuracy,special)
  Move tackle{"Tackle",Type::normal,4,40,100};
  Move dragon_breath{"Dragon Breath",Type::dragon,20,60,100};

};

#endif 
