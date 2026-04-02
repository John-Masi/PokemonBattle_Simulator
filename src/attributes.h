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
  static constexpr float typechart[17][17] = {
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
static float modifier(const T t1, const T t2) {
  return Typechart::typechart[t1][t2];
}

enum Type {
  // Do not change none to anything but zero will mess up the type chart matrix when calculating type effectivness 
  // It is here for monotype pokemon 
  none = 0,
  normal = 0,
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

 struct Nature {
    int inc_stat{};
    int dec_stat{};
    constexpr explicit Nature(int inc_stat,int dec_stat) : inc_stat(inc_stat), dec_stat(dec_stat){}
};

namespace NatureTable {
  // This follows the indices of the stats array in species
  constexpr static Nature none{6,6};
  constexpr static Nature hardy{2,2};
  constexpr static Nature lonely{2,3};
};

struct Species {
  Type types[2];
  // [0] - hp, [1] - attk, [2] - def, [3] - [speed] , [4] - Spdef, [5] - SpAttk, [6] - empty stat tag 
  uint16_t stats[7] = {0,0,0,0,0,0,0};

  constexpr explicit Species(uint16_t hp,uint16_t attk,uint16_t def,uint16_t speed,uint16_t SpDef,uint16_t SpAttk,Type t1 = Type::none,Type t2 = Type::none,const Nature& n = NatureTable::none) { 
    types[0] = t1;
    types[1] = t2;
    
    // Stats assignment
    stats[0] = hp;
    stats[1] = attk;
    stats[2] = def;
    stats[3] = speed;
    stats[4] = SpDef;
    stats[5] = SpAttk;

    
    stats[n.inc_stat] = stats[n.inc_stat] * (11/10);
    stats[n.dec_stat] = stats[n.dec_stat] * (9/10);
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
  std::string name;
  uint16_t level{1};
  uint16_t exp{1};
  Pokemon(const std::string& name,const Species& sp): name(name),sp(sp) {
    moves.reserve(4);
  }
  void learnMove(Move& m);
  void printMoves();
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

inline void Pokemon::printMoves() {
  std::cout << moves.capacity() << "\n";
  std::for_each(moves.begin(),moves.end(),[](const Move& m)  {
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
    
    // STAB Caclulation 
    if(a_pkmn.sp.types[0] == move.move_Type || a_pkmn.sp.types[1] == move.move_Type) {
      stab = 1.5;
    }

    dmg =  ((((2.0 * static_cast<float>(a_pkmn.level) / 5.0 ) + 2.0)) * (move.attk * a_pkmn.sp.stats[0] 
                    / t_pkmn.sp.stats[1]) / 50.0) + 2.0 * stab * type;
  
  }
};

#endif 
