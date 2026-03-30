#include <vector>
#include "attributes.h"
#include <algorithm>
#include <ranges> 

#ifndef TRAINER_HPP
#define TRAINER_HPP

class Trainer {

    public:
      

      Trainer(const int money) : money(money) {
        team.reserve(6);
      };
      ~Trainer() = default;


      void addMember(Pokemon& pokemon);
      Pokemon& getLeader();
      void printTeam();
      bool hasFainted();

      mutable int money{};
      std::vector<Pokemon> team;

};

#endif 
