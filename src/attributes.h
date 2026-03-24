#include <cstdint>
#include <utility> 
#include <string> 
#include <array>
#include <optional>
#include <string_view>
#include <unordered_map> 

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

namespace Typechart {
  float typechart[16][16] = {
    // Normal type 
    {1,2,1,1,1,1,1,1,1,1,1,0.5,0,1,1},
    // Fire type 
    {1,0.5,0.5,2,1,2,1,1,1,1,2.0,0.5,1,0.5,1},
    // Water type 
    {1,2,0.5,0.5,1,1,1,1,2,1,1,1,2,0.5,1},
  };

};

template <typename T>
float modifier(T t1,T t2) {
  return Typechart::typechart[t1][t2];
}


enum Type {
  normal,
  fire,
  water,
  electric,
  ice,
  fighting,
  poison,
  ground,
  flying,
  psychic,
  bug,
  rock,
  ghost,
  dragon,
  dark,
};

enum Nature {


};

struct Species {
  std::string_view name{};
  Type types[2];
  uint16_t hp{};
  uint16_t attk{};
  uint16_t def{};
  uint16_t speed{};
  uint16_t SpDef{};
  uint16_t SpAttk{};

  Species(std::string name,uint16_t hp,uint16_t attk,uint16_t def,uint16_t speed,uint16_t SpDef,uint16_t SpAttk) 
  : name(name) ,hp(hp), attk(attk), def(def), speed(speed), SpDef(SpDef), SpAttk(SpAttk){

  }
};

struct Move {
  std::string_view move_Name;
  Type move_Type{};
  uint8_t pp{};
  uint8_t attk{};
  uint8_t accuracy{};

  explicit Move(std::string move_Name,Type move_Type,uint8_t pp,uint8_t attk,uint8_t accuracy) 
  : move_Name(move_Name), move_Type(move_Type), pp(pp), attk(attk), accuracy(accuracy){}
};

struct Pokemon {
  Species sp;
  std::array<std::optional<Move>, 4> moves;
  uint16_t level;
  uint16_t exp;
  Pokemon(Species& sp): sp(sp) {}
  void natureMath(uint16_t stat_1,uint16_t stat_2);
  void learnMove(Move& m);
};

void Pokemon::natureMath(uint16_t stat_1,uint16_t stat_2){
  stat_1 = stat_1 * (11/10);
  stat_2 = stat_2 * (9/10);
}
void Pokemon::learnMove(Move& m) {
  moves[0] = m;
}

struct Dmg {
  Pokemon a_pkmn;
  Pokemon t_pkmn;
  Move move;

  float stab{1.0};
  float type{1.0};
  float dmg{0.0};

  explicit Dmg(Pokemon& a_pkmn,Pokemon& t_pkmn,Move& move) : a_pkmn(a_pkmn), t_pkmn(t_pkmn), move(move){
    // Type effective Calculation
    type = modifier(move.move_Type,t_pkmn.sp.types[0]);
    
    // STAB Caclulation 
    if((move.move_Type == a_pkmn.sp.types[0]) || (a_pkmn.sp.types[1])) {
        stab = 1.5;
    }

    dmg = (((2 * a_pkmn.level) * move.attk * a_pkmn.sp.attk 
                    / (a_pkmn.sp.def) / 50.0) + 2) * stab;
  
  }
};

#endif 
