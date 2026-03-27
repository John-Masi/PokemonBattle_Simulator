#include "trainer.hpp"

Pokemon& Trainer::getLeader() {
  return team[0];

}

bool hasFainted() {
  return false;
}

void Trainer::addMember(Pokemon& pokemon) {
  team.emplace_back(pokemon);
};

void Trainer::printTeam() {
  std::for_each(team.begin(),team.end(),
    [](Pokemon p) { std::cout << p.sp.name; });
}

