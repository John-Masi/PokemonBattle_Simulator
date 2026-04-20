#include "trainer.hpp"


// Change to score every attack instead of just one
// And just the score the attacks of the leading pokemon
using Moves = std::variant<Move,Effect>;
void Trainer::scoreATTK(const std::shared_ptr<Pokemon>& t_pkmn) {
 
  for(auto& n: team.team[0]->moves) {
    Moves w = std::visit([](auto&& arg) -> Moves { return arg; }, n);



    std::visit([&](auto&& arg){
      using T = std::decay_t<decltype(arg)>;
      if constexpr(std::is_same_v<T,Move>) {
        int score{100};
        // if a 
        float tmod = modifier(arg.move_Type,t_pkmn->sp.types[0]);
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
        dmg.dmgCalc(team.team[0],t_pkmn,arg);
        if(dmg.stab == 1.5) {
          score += 50;
        }
        std::cout << score;

      }
    }, w);
  }


}

bool Trainer::shouldSwap(const std::shared_ptr<Pokemon>& p) {
  // If we are weak against the target Pokemon
  if(modifier(team.team[0]->sp.types[0],p->sp.types[0]) < 1.0) {
    return true;
  }
  return false;
}


