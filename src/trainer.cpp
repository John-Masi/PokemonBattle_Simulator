#include "trainer.hpp"

Pokemon& Trainer::getLeader() {
  return *team[0];

}

void Trainer::addMember(Pokemon& pokemon) {
  team[0].emplace(pokemon);
};


