#include "attributes.h"
#include "team.h"

#ifndef TRAINER_HPP
#define TRAINER_HPP

// Trainer AI 
class Trainer {

    public:
      
      Team team;
      Trainer(const Team& team) : team(team) {
      };
      ~Trainer() = default;
      
      // Select the best move
      void moveSelection();

};

#endif 
