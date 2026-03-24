#include <variant> 
#include <optional> 
#include <iostream>
#include "attributes.h"
#include "trainer.cpp"
#include "data.h"

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
        Pokemon* p_1{nullptr};
        Pokemon* p_2{nullptr};
        // If either teams are all hp = 0 or not
        bool p_feint{};
        bool t_feint{};
        
        Battle(Trainer& t1,Trainer& t2) {
            p_1 = &t1.getLeader();
            p_2 = &t1.getLeader();
        }
        ~Battle() {
        }
      
        void turn();
        void battle();
        void swap_Pokemon(Pokemon& pokemon);
        std::optional<Move> select_Move();
        float dmgCalc(Pokemon& a_pkmn,Pokemon& t_pkmn,Move& move); 
        bool feintCheck(Trainer& trainer);
};

#endif 
