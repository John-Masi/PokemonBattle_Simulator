#include "attributes.h"
#include <memory>

#ifndef DMG_H
#define DMG_H

struct Dmg {
  float stab{1.0};
  float type{0.0};
  float dmg{1.0};

  void dmgCalc(const std::shared_ptr<Pokemon>& a_pkmn,const std::shared_ptr<Pokemon>& t_pkmn,const Move& move) {
    type = modifier(move.move_Type,t_pkmn->sp.types[0]);
        
    // STAB Caclulation 
    if(a_pkmn->sp.types[0] == move.move_Type || a_pkmn->sp.types[1] == move.move_Type) {
        stab = 1.5;
    }

    dmg =  ((((2.0 * static_cast<float>(a_pkmn->level) / 5.0 ) + 2.0)) * (move.attk * a_pkmn->sp.stats[0] 
            / t_pkmn->sp.stats[1]) / 50.0) + 2.0 * stab * type;
        
  }
};



#endif 
