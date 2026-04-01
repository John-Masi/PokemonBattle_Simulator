#include "trainer.hpp"

Pokemon& Trainer::getLeader() {
  return team[0];

}

bool Trainer::hasFainted() {
  int faintCount = std::ranges::count_if(team.begin(),team.end(), [](const Pokemon& p) { return p.sp.stats[0] == 0; });
  if(faintCount == 6) {
    return true;    
  }
  return false;
}

void Trainer::addMember(Pokemon& pokemon) {
  if(team.size() > 5 ){

  }
  else {
    team.emplace_back(pokemon.sp);
  }
};

void Trainer::printTeam() {
  std::for_each(team.begin(),team.end(),
    [](const Pokemon& p) { std::cout << p.level; });
}

