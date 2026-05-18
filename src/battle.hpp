#include "../include/data.h"
#include <optional> 
#include <functional> 
#include <iostream>
#include "trainer.hpp"
#include "player.hpp"

#ifndef BATTLE_HPP
#define BATTLE_HPP

using type = std::vector<Pokemon>;
class Battle {
      public:
        // Current pokemon battleing 
        mutable bool start{true};
        std::vector<Pokemon> *player{nullptr};
        Trainer trainer;
        // If either teams are all hp = 0 or not
        
        Battle(Trainer& trainer) : player(player), trainer(trainer) {
          auto t = team_2();
          player = &t;
        }
        ~Battle() = default;
      
        void battle();
};

#endif 
