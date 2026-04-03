#include "attributes.h"
#include <vector>
#include <algorithm>
#include <ranges>
#include <iostream>
#include <memory>

#ifndef TEAM
#define TEAM

struct Team {
   std::vector<std::shared_ptr<Pokemon>> team;
    
   Team() {

   }
   
   void printTeam() const;
   bool teamFainted();
   void addMember(const std::string& name,Species& sp);
};

inline void Team::addMember(const std::string& name,Species& sp) {
  team.push_back(std::make_shared<Pokemon>("name",sp));
}

inline void Team::printTeam() const {
    std::for_each(team.begin(),team.end(),[](const std::shared_ptr<Pokemon>& p) { std::cout << p->name << " " << " lvl: " << p->level; });
}

inline bool Team::teamFainted() {
  auto count = std::ranges::count_if(team.begin(),team.end(),[](const std::shared_ptr<Pokemon>& p) { return p->sp.stats[0] == 0; });

  if(count == 6) {
    return true;
  }

  return false;
}

#endif 
