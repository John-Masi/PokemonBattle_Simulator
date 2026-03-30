#include "battle.hpp"


void Battle::swap_Pokemon(Pokemon& pokemon) {
  if(state == b_State::p_turn) {
    p_1 = &pokemon;
  }
  else if(state == b_State::t_turn) {
    p_2 = &pokemon;
  }
}

std::optional<Move> Battle::select_Move() {
  return std::nullopt;
}

void Battle::battle() {
  while(state != b_State::b_end) {
    std::string option;
    std::cout << "enter a move" << "\n";
    std::cin >> option;
    if(option == "end") {
      state = b_State::b_end;
    }
  }
}

void Battle::turn() {
  // Check if either trainers entire team is fainted or not 
  switch(state) {
    case(b_State::p_turn) : {
      std::cout << "Please select the move you would like to use";
      p_1->printMoves();
      int moveSelected;
      std::cin >> moveSelected;
      Dmg dmgCalc(*p_1,*p_2,p_1->moves[moveSelected]);
    };
    case(b_State::t_turn) : {
      // System to decide the trainers move
    };
  }
}

// a_pkmn(attacking pokemon) t_pkmn(target pokemon)
float Battle::dmgCalc(Pokemon& a_pkmn,Pokemon& t_pkmn,Move& move) {
  Dmg moveDmg{a_pkmn,t_pkmn,move}; 

  return moveDmg.dmg;
}
