#include <string>
#include <vector> 
#include <cstdint>
#include "types.h"

#ifndef MOVE_H
#define MOVE_H 

struct Move {
  std::string move_Name;
  Type move_Type{};
  uint8_t pp{};
  uint8_t attk{};
  uint8_t accuracy{};

  explicit Move(const std::string& move_Name,Type move_Type,uint8_t pp,uint8_t attk,uint8_t accuracy) 
  : move_Name(move_Name), move_Type(move_Type), pp(pp), attk(attk), accuracy(accuracy){}
};

#endif 
