#include "data.h"
#include <vector>
#include <algorithm>
#include <ranges>
#include <iostream>
#include <memory>

#ifndef TEAM
#define TEAM

struct Team {
    
  // TODO: Find a cleaner alternative
  // Remove struct then reactor methods into general functions
  std::vector<std::shared_ptr<Pokemon>> team;
  std::shared_ptr<Pokemon> leader;
  Team() {

  }

   void swapLeader();
   void printTeam() const;
   bool teamFainted();
   void addMember(const std::string& name,Species& sp);
};

inline void Team::addMember(const std::string& name,Species& sp) {
  team.push_back(std::make_shared<Pokemon>(name,sp));
  leader = team[0];
}

// TODO: Create funcs that just take in a struct Team

// Print team for trainer battle
inline void Team::printTeam() const {
    std::for_each(team.begin(),team.end(),[](const std::shared_ptr<Pokemon>& p) { std::cout << p->name << " " << " lvl: " << p->level; });
}

// Check if a trainers team is fainted or not
inline bool Team::teamFainted() {
  auto count = std::ranges::count_if(team.begin(),team.end(),[](const std::shared_ptr<Pokemon>& p) { return p->hp == 0; });

  if(count == 6) {
    return true;
  }

  return false;
}

inline std::vector<Pokemon> team_2() {
  Pokemon p{"Hey",SpeciesTable::squirtle};

  std::vector<Pokemon> t;
  
  t.push_back(p);

  return t;
}

#endif 
