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
#include "nature.h"
#include "species.h"

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

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

using Moves = std::variant<Move,Effect>;
struct Pokemon {
  Species sp;
  std::vector<Moves> moves;
  std::string name;
  uint16_t ivs[6] = {0,0,0,0,0,0};
  uint16_t level{1};
  uint16_t exp{1};
  uint16_t hp{0};
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
