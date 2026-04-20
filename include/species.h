#ifndef SPECIES_H
#define SPECIES_H

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

#endif 
