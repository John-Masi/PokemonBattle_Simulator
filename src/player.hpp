#include "../include/team.h"
#include <string> 

#ifndef PLAYER_HPP
#define PLAYER_HPP

// Player 
class Player {

  public:
    std::string name;
    Team team;
    Player(const std::string& name,const Team& team) : name(name),team(team) {

    }
    ~Player() = default;
  private:

};

#endif
