#ifndef NATURE_H
#define NATURE_H

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

#endif 
