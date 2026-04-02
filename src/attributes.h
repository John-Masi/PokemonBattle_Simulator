#include <cstdint>
#include <utility> 
#include <string> 
#include <vector>
#include <algorithm>
#include <iostream> 
#include "move.h"
#include "types.h"

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

// TODO - Add ev's and iv's

struct Nature {
    int inc_stat{};
    int dec_stat{};
    constexpr explicit Nature(int inc_stat,int dec_stat) : inc_stat(inc_stat), dec_stat(dec_stat){}
};

namespace NatureTable {
  // This follows the indices of the stats array in species
  //  Find a better implmentation of this because i did not realize that it goes in order of stats
  constexpr static Nature none{5,5};
  constexpr static Nature hardy{2,2};
  constexpr static Nature lonely{2,3};
  constexpr static Nature adamant{1,4};
  constexpr static Nature naughty{1,3};
  constexpr static Nature bold{1,0};
  constexpr static Nature docile{1,1};
  constexpr static Nature relaxed{1,2};
  constexpr static Nature impish{1,4};
  constexpr static Nature lax{1,3};
  constexpr static Nature timid{2,0};
  constexpr static Nature hasty{2,1};
  constexpr static Nature serious{2,2};
  constexpr static Nature jolly{2,4};
  constexpr static Nature naive{2,3};
  constexpr static Nature modest{4,0};
  constexpr static Nature mild{4,1};
  constexpr static Nature quiet{4,2};
  constexpr static Nature bashful{4,4};
  constexpr static Nature rash{4,3};
  constexpr static Nature calm{3,0};
  constexpr static Nature gentle{3,1};
  constexpr static Nature sassy{3,2};
  constexpr static Nature careful{3,4};
  constexpr static Nature quirky{3,3};

};

struct Species {
  Type types[2];
  //  [0] - attk, [1] - def, [2] - [speed] , [3] - Spdef, [4] - SpAttk, [5] - empty stat tag 
  uint16_t stats[6] = {0,0,0,0,0,0};

  constexpr explicit Species(uint16_t attk,uint16_t def,uint16_t speed,uint16_t SpDef,uint16_t SpAttk,Type t1 = Type::none,Type t2 = Type::none,const Nature& n = NatureTable::none) { 
    types[0] = t1;
    types[1] = t2;
    
    // Stats assignment
    stats[0] = attk;
    stats[1] = def;
    stats[2] = speed;
    stats[3] = SpDef;
    stats[4] = SpAttk;

    
    stats[n.inc_stat] = stats[n.inc_stat] * (11/10);
    stats[n.dec_stat] = stats[n.dec_stat] * (9/10);
  }
};

struct Pokemon {
  Species sp;
  std::vector<Move> moves;
  std::string name;
  uint16_t level{1};
  uint16_t exp{1};
  uint16_t hp{1};
  Pokemon(const std::string& name,const Species& sp): name(name), sp(sp){
    moves.reserve(4);
  }
  void learnMove(Move& m);
  void printMoves() const ;
  float dmgCalc(const Pokemon& t_pkmn,const Move& move);
};

inline void Pokemon::learnMove(Move& m) {
  if(moves.size() > 3) {
    std::cout << "exceeded move limit";
    // Handle replacing a move when we are full of moves
  }
  else {
    moves.emplace_back(m.move_Name,m.move_Type,m.pp,m.attk,m.accuracy);
  }
}

inline void Pokemon::printMoves() const {
  std::cout << moves.capacity() << "\n";
  std::for_each(moves.begin(),moves.end(),[](const Move& m)  {
    std::cout << m.move_Type <<" PP: " << static_cast<unsigned int>(m.pp) << 
      " Name: " << m.move_Name << "\n";
    

  });
}

inline float Pokemon::dmgCalc(const Pokemon& t_pkmn,const Move& move) {
    // Type effective Calculation
    float stab{1.0};
    auto type = modifier(move.move_Type,t_pkmn.sp.types[0]);
    
    // STAB Caclulation 
    if(sp.types[0] == move.move_Type || sp.types[1] == move.move_Type) {
      stab = 1.5;
    }

    auto dmg =  ((((2.0 * static_cast<float>(level) / 5.0 ) + 2.0)) * (move.attk * sp.stats[0] 
                    / t_pkmn.sp.stats[1]) / 50.0) + 2.0 * stab * type;
      
    return dmg;
}


#endif 
