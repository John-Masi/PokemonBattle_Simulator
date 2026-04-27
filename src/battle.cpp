#include "battle.hpp"


void Battle::battle() {
  bool run{true};
  bool isFaint{trainer.team.team.teamFainted()};
  while(run) {
    

    std::cout << "Please select move";
    Trainer.team.team.printTeam();
    Player.team.team.printTeam();



    // After every turn check if the team is fainted
    isFaint = trainer.team.team.teamFainted();
    if(isFaint) {
      run = false;
    }

  }
}

