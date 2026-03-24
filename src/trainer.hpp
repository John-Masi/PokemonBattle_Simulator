#include "attributes.h"
#include <array>
#include <optional>

#ifndef TRAINER_HPP
#define TRAINER_HPP

class Trainer {

    public:
      

      Trainer(int money) : money(money) {};
      ~Trainer() = default;


      void addMember(Pokemon& pokemon);
      Pokemon& getLeader();

      mutable int money{};
      std::array<std::optional<Pokemon>,6> team;

};

#endif 
