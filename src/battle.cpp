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

}

void Battle::battle() {
  while(state != b_State::b_end) {
    std::string option{""};
    std::cout << "enter a move" << "\n";
    
    std::cin >> option;
    if(option == "end") {
      state = b_State::b_end;
    }
  }
}

bool Battle::feintCheck(Trainer& trainer) {

}

b_State Battle::turn() {
  // Check if either trainers entire team is fainted or not 
  switch(state) {
    case(b_State::p_turn) : {
      // Handle if a pokemon feints we swap into a new one
      return b_State::p_turn;
    };
    case(b_State::t_turn) : {
      return b_State::t_turn;
    };
  }
}

// a_pkmn(attacking pokemon) t_pkmn(target pokemon)
float Battle::dmgCalc(Pokemon& a_pkmn,Pokemon& t_pkmn,Move& move) {
  Dmg moveDmg{a_pkmn,t_pkmn,move}; 

  return moveDmg.dmg;
}
