#include "attributes.h"
#include <vector> 
#include <algorithm>

#ifndef TRAINER_HPP
#define TRAINER_HPP

class Trainer {

    public:
      

      Trainer(int money) : money(money) {};
      ~Trainer() = default;


      void addMember(Pokemon& pokemon);
      Pokemon& getLeader();
      void printTeam();
      bool hasFainted();

      mutable int money{};
      std::vector<Pokemon> team;

};

#endif 
