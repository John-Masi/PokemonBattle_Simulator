#include "attributes.h"
#include <vector>
#include <algorithm>
#include <ranges>
#include <iostream>

#ifndef TEAM
#define TEAM

struct Team {
   std::vector<Pokemon> team;
    
   Team() {
      team.reserve(6);
   }
   
   void printTeam() const;
   bool teamFainted();
   void addMember(const std::string& name,const Species& sp);
};

inline void Team::addMember(const std::string& name,const Species& sp) {
  team.emplace_back(name,sp);
}

inline void Team::printTeam() const {
    std::for_each(team.begin(),team.end(),[](const Pokemon& p) { std::cout << p.name << " " << " lvl: " << p.level; });
}

inline bool Team::teamFainted() {
  auto count = std::ranges::count_if(team.begin(),team.end(),[](const Pokemon& p) { return p.sp.stats[0] == 0; });

  if(count == 6) {
    return true;
  }

  return false;
}

#endif 
