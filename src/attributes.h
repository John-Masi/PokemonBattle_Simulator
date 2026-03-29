#include <cstdint>
#include <utility> 
#include <string> 
#include <vector>
#include <string_view>
#include <algorithm>
#include <iostream> 

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

namespace Typechart {
  float typechart[17][17] = {
    // Normal type 
    {1,2,1,1,1,1,1,1,1,1,1,0.5,0,1,1},
    // Fire type 
    {1,0.5,0.5,2,1,2,1,1,1,1,2.0,0.5,1,0.5,1},
    // Water type 
    {1,2,0.5,0.5,1,1,1,1,2,1,1,1,2,0.5,1},
    // Grass type
    {1,0.5,2,0.5,1,1,1,0.5,2,0.5,1,0.5,2,1,0.5,1,0.5},
    // Electric type 
    {1,1,2,0.5,0.5,1,1,1,0,2,1,1,1,1,0.5,1,1},
    // Ice
    {1,0.5,0.5,2,1,0.5,1,1,2,2,1,1,1,1,2,1,0.5},
    // Fighting 
    {2,1,1,1,1,2,1,0.5,1,0.5,0.5,0.5,2,0,1,2,2},
    // Poison
    {1,1,1,2,1,1,1,0.5,0.5,1,1,1,0.5,0.5,1,1,0},
    // Ground 
    {1,2,1,0.5,2,1,1,2,1,0,1,0.5,2,1,1,1,2},
    // Flying 
    {1,1,1,2,0.5,1,2,1,1,1,1,2,0.5,1,1,1,0.5},
    // Psychic
    {1,1,1,1,1,1,2,2,1,1,0.5,1,1,1,1,0,0.5},
    // Bug 
    {1,0.5,1,2,1,1,0.5,0.5,1,0.5,2,1,1,0.5,1,2,0.5},
    // Rock
    {1,2,1,1,1,2,0.5,1,0.5,2,1,2,1,1,1,1,0.5},
    // Ghost
    {0,1,1,1,1,1,1,1,1,1,2,1,1,2,1,0.5,1},
    // Dragon
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,0.5},
    // Dark
    {1,1,1,1,1,1,0.5,1,1,1,2,1,1,2,1,0.5,1},
    // Steel
    {1,0.5,0.5,1,0.5,2,1,1,1,1,1,1,2,1,1,1,0.5}
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
  grass,
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
  steel
};

enum Nature {


};

struct Species {
  std::string name;
  Type types[2];
  uint16_t hp{};
  uint16_t attk{};
  uint16_t def{};
  uint16_t speed{};
  uint16_t SpDef{};
  uint16_t SpAttk{};

  Species(const std::string& name,uint16_t hp,uint16_t attk,uint16_t def,uint16_t speed,uint16_t SpDef,uint16_t SpAttk,Type t1 = Type::normal,Type t2 = Type::normal) 
  : name(name) ,hp(hp), attk(attk), def(def), speed(speed), SpDef(SpDef), SpAttk(SpAttk){
    types[0] = t1;
    types[1] = t2;
  }
};

struct Move {
  std::string move_Name;
  Type move_Type{};
  uint8_t pp{};
  uint8_t attk{};
  uint8_t accuracy{};

  explicit Move(const std::string& move_Name,Type move_Type,uint8_t pp,uint8_t attk,uint8_t accuracy) 
  : move_Name(move_Name), move_Type(move_Type), pp(pp), attk(attk), accuracy(accuracy){}
};

struct Pokemon {
  Species sp;
  std::vector<Move> moves;
  uint16_t level{};
  uint16_t exp{};
  Pokemon(Species& sp): sp(sp) {
    moves.reserve(4);
  }
  void natureMath(uint16_t stat_1,uint16_t stat_2);
  void learnMove(Move& m);
  void printMoves();
};

void Pokemon::natureMath(uint16_t stat_1,uint16_t stat_2){
  stat_1 = stat_1 * (11/10);
  stat_2 = stat_2 * (9/10);
}
void Pokemon::learnMove(Move& m) {
  if(moves.size() > 3) {
    std::cout << "exceeded move limit";
    // Handle replacing a move when we are full of moves
  }
  else {
    moves.emplace_back(m.move_Name,m.move_Type,m.pp,m.attk,m.accuracy);
  }
}

void Pokemon::printMoves() {
  std::cout << moves.capacity() << "\n";
  std::for_each(moves.begin(),moves.end(),[](Move m)  {
    std::cout << m.move_Type <<" PP: " << static_cast<unsigned int>(m.pp) << 
      " Name: " << m.move_Name << "\n";
    

  });
}

struct Dmg {
  Pokemon a_pkmn;
  Pokemon t_pkmn;
  Move move;

  float stab{1.0};
  float type{1.0};
  float dmg{};

  explicit Dmg(const Pokemon& a_pkmn,const Pokemon& t_pkmn,const Move& move) : a_pkmn(a_pkmn), t_pkmn(t_pkmn), move(move){
    // Type effective Calculation
    type = modifier(move.move_Type,t_pkmn.sp.types[0]);
    std::cout << type;
    
    // STAB Caclulation 
    if(a_pkmn.sp.types[0] == move.move_Type || a_pkmn.sp.types[1] == move.move_Type) {
      stab = 1.5;
    }

    dmg =  ((((2.0 * static_cast<float>(a_pkmn.level) / 5.0 ) + 2.0)) * (move.attk * a_pkmn.sp.attk 
                    / t_pkmn.sp.def) / 50.0) + 2.0 * stab * type;
  
  }
};

#endif 
