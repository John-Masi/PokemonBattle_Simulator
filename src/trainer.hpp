#include "../include/attributes.h"
#include "../include/team.h"
#include "../include/dmg.h"
#include <memory>

#ifndef TRAINER_HPP
#define TRAINER_HPP

// Trainer AI 
class Trainer {

    public:
      
      Team team;
      Trainer(const Team& team) : team(team) {
      };
      ~Trainer() = default;
      
      // Scoring for attack move against target pokemon
      int scoreATTK(const Move& move,const std::shared_ptr<Pokemon>& t_pkmn);
      // Scoring every move and then selecting the highest score
      Move selectMove();

      // When the trainer ai should swap out pokemon
      bool shouldSwap(); 

};

#endif 
