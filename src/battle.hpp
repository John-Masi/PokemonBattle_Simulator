#include <optional> 
#include <iostream>
#include "attributes.h"
#include "trainer.hpp"
#include "player.hpp"

#ifndef BATTLE_HPP
#define BATTLE_HPP

// Player turn, Trainer turn, battle end 
enum class b_State {
  p_turn,
  t_turn,
  b_end,
};

class Battle {
      public:
        // Current pokemon battleing 
        mutable bool start{true};
        b_State state{b_State::p_turn};
        Player player;
        Trainer trainer;
        // If either teams are all hp = 0 or not
        
        Battle(Player& player,Trainer& trainer) : player(player), trainer(trainer) {
        
        }
        ~Battle() = default;
      
        void turn();
        void battle();
        std::optional<Move> select_Move();
};

#endif 
