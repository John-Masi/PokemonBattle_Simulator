#include "battle.hpp"


void Battle::battle() {
  bool run{true};
  bool isFaint{false};

  while(run) {
    

    std::cout << "Please select move";
    team.team.printTeam();
    player.team.printTeam();

    // TODO: Handle case when the pokemon on the field is ditto

    // After every turn check if the team is fainted
    isFaint = trainer.team.teamFainted();
    if(isFaint) {
      run = false;
    }

  }
}

