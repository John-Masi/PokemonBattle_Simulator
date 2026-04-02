#include "battle.hpp"

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
      int moveSelected;
      std::cin >> moveSelected;
    };
    case(b_State::t_turn) : {
      // System to decide the trainers move
    };
  }
}


