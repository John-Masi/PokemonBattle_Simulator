#include <cstdint>
#include <variant>
#include <utility> 
#include <string> 
#include <vector>
#include <optional> 
#include <type_traits>
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
  constexpr Nature none{5,5};
  constexpr Nature hardy{2,2};
  constexpr Nature lonely{2,3};
  constexpr Nature adamant{1,4};
  constexpr Nature naughty{1,3};
  constexpr Nature bold{1,0};
  constexpr Nature docile{1,1};
  constexpr Nature relaxed{1,2};
  constexpr Nature impish{1,4};
  constexpr Nature lax{1,3};
  constexpr Nature timid{2,0};
  constexpr Nature hasty{2,1};
  constexpr Nature serious{2,2};
  constexpr Nature jolly{2,4};
  constexpr Nature naive{2,3};
  constexpr Nature modest{4,0};
  constexpr Nature mild{4,1};
  constexpr Nature quiet{4,2};
  constexpr Nature bashful{4,4};
  constexpr Nature rash{4,3};
  constexpr Nature calm{3,0};
  constexpr Nature gentle{3,1};
  constexpr Nature sassy{3,2};
  constexpr Nature careful{3,4};
  constexpr Nature quirky{3,3};

};

enum stat_tag {
  ATTACK,
  DEF,
  SPEED,
  SP_ATTK,
  SP_DEF,
  NONE
};

struct EffortValues {
  std::pair<stat_tag,uint16_t> evs[3];

  EffortValues(const stat_tag tag_1,const uint16_t mod_1,const stat_tag tag_2,const uint16_t mod_2,const stat_tag tag_3,const uint16_t mod_3) {
    evs[0].first = tag_1;
    evs[0].second = mod_1;
    evs[1].first = tag_2;
    evs[1].second = mod_2;
    evs[2].first = tag_3;
    evs[2].second = mod_3;
  }
};

struct Species {
  Type types[2];
  //  [0] - attk, [1] - def, [2] - [speed] , [3] - Spdef, [4] - SpAttk, [5] - empty stat tag 
  uint16_t stats[6] = {0,0,0,0,0,0};
  uint16_t stat_mod[6] = {0,0,0,0,0,0};

  explicit Species(uint16_t attk,uint16_t def,uint16_t speed,uint16_t SpDef,uint16_t SpAttk,Type t1 = Type::none,Type t2 = Type::none,const Nature& n = NatureTable::none) { 
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

using Moves = std::variant<Move,Effect>;
struct Pokemon {
  Species sp;
  std::vector<Moves> moves;
  std::string name;
  uint16_t ivs[6] = {0,0,0,0,0,0};
  uint16_t level{1};
  uint16_t exp{1};
  uint16_t hp{1};
  Pokemon(const std::string& name,Species& sp,const std::optional<EffortValues> ev = std::nullopt): name(name), sp(sp){
    if(ev.has_value()) {
      for(int i = 0; i < 3; i ++) {
        sp.stats[ev.value().evs[i].first] = ((2 * sp.stats[ev.value().evs[i].first] + (ev.value().evs[i].second / 4) * level ) / 100)  +5;
      }
    }
    moves.reserve(4);
  }
  void learnAttk(const Move& m);
  void learnEffect(const Effect& e);
  void printMoves() const ;
};

inline void Pokemon::learnAttk(const Move& m) {
    moves.emplace_back(std::in_place_type<Move> ,m.move_Name,m.move_Type,m.pp,m.attk,m.accuracy);
}

inline void Pokemon::learnEffect(const Effect& e){
    moves.emplace_back(std::in_place_type<Effect>, e.eff,e.move_Name,e.pp,e.accuracy);
}

template <class... Ts>
struct overload : Ts... {using Ts::operator() ...;};
template <class... Ts> 
overload(Ts...) -> overload<Ts...>;

inline void Pokemon::printMoves() const {
  for(auto& n: moves) {
    std::visit(overload{
      [](auto arg) { std::cout << arg; },
      [](const Move& m) { std::cout << "Move Name: " << m.move_Name << "\n"; },
      [](const Effect& e) { std::cout << "Move Name: "<< e.move_Name << "\n"; }
    },n);
  }
}


#endif 
