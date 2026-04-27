#include <optional> 
#include <iostream>
#include "trainer.hpp"
#include "player.hpp"

#ifndef BATTLE_HPP
#define BATTLE_HPP

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
      
        void battle();
};

#endif 
