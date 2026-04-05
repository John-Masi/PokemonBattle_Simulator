#include "trainer.hpp"


int Trainer::scoreATTK(const Move& move,const std::shared_ptr<Pokemon>& t_pkmn) {
  int score{100};
  // if a 
  float tmod = modifier(move.move_Type,t_pkmn->sp.types[0]);
  if(tmod >= 2.0 || tmod <= 4.0) {
    score += 25;
  } 
  else if (tmod >= 0.25 || tmod <= 0.50) {
    score -= 25;
  }
  else {
    score -= 75;
  }

  Dmg dmg;
  dmg.dmgCalc(team.team[0],t_pkmn,move);
  if(dmg.stab == 1.5) {
    score += 50;
  }

  return score;
}


