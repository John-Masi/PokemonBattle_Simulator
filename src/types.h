
#ifndef TYPES_H
#define TYPES_H

namespace Typechart {
  static float typechart[17][17] = {
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
float modifier(const T t1, const T t2) {
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

#endif 
