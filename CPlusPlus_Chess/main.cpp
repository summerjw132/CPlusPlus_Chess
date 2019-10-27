//
//  main.cpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 9/19/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include "Engine/GameEngine.hpp"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void game(){
    BuildGame();
    StartGame();
    while(!WinConditionWasMet()){
        PlayerTurnStart();
        while(!PlayerTurnHasEnded()){
            PlayerMoveStart();
            while(PlayerStillHasActions()){
                PlayerMoveAction();
            }
            PlayerMoveEnd();
        }
        PlayerTurnEnd();
    }
    PlayerWin();
    EndGame();
    //TODO: DeconstructGame()/UnBuildGame()?
}




int main(int argc, const char * argv[]) {
    game();
    //get start and end coordinates into a list (vector)
//    cout << "Received input, getting start and end coordinates...\n";
//    vector<string> vectorOfStartAndEndCoordinates = delineateString("2:4,2:8", ',');
//
//    //for each coordinate, get individual coordinate values into a list (vector)
//    for (int i=0; i<vectorOfStartAndEndCoordinates.size(); i++) {
//
//        cout << "Delineating individual coordinate values...\n";
//        vector<string> vectorOfCoordinateValues = delineateString(vectorOfStartAndEndCoordinates[i], ':');
//        cout << "\n";
//    }
    cout << "\n\n";
    return 0;
}
