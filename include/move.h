#include <string>
#include <functional>
#include <vector> 
#include <cstdint>
#include "types.h"

#ifndef MOVE_H
#define MOVE_H 


// For only attack moves
struct Move {
  std::string move_Name;
  Type move_Type{};
  uint8_t pp{};
  uint8_t attk{};
  uint8_t accuracy{};

  explicit Move(const std::string& move_Name,Type move_Type,uint8_t pp,uint8_t attk,uint8_t accuracy) 
  : move_Name(move_Name), move_Type(move_Type), pp(pp), attk(attk), accuracy(accuracy){}
};

// Effect tag this will let us call a certain member func of effect depending on tag
enum ETag {
  NILL,
  PROTECT,
  SWORD_DANCE
};

// Effect for status moves
struct Effect {
  // Follows indicies for stats in species struct 
  std::string move_Name;
  Type move_Type{};
  uint8_t pp{};
  uint8_t accuracy{};
  ETag etag;
  std::function<void()> eff;
  

  uint16_t stat_mod[6] = {0,0,0,0,0,0};  

  explicit Effect(std::function<void()> e,const std::string& move_Name,uint8_t pp,uint8_t accuracy) 
    : eff(e),move_Name(move_Name), move_Type(move_Type), pp(pp), accuracy(accuracy){
  }
  
};

#endif 
 
