//
//  GameEngine.hpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 9/20/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void BuildGame();
void StartGame();
int SwitchPlayerTurn();
int GetCurrentPlayer();
void PlayerTurnStart();
void resetVariables();
bool PlayerTurnHasEnded();
void PlayerMoveStart();
void PlayerMoveAction();
bool PlayerStillHasActions();
void PlayerMoveEnd();
void EndTurn();
void PlayerTurnEnd();
void TriggerWinCondition(int theWinningPlayer);
bool WinConditionWasMet();
void PlayerWin();
void EndGame();

bool validResponseInput(string inputString, string listOfValidMoves[]);

vector<int> convertCoordinatesToInt(string coordinates);
#endif /* GameEngine_hpp */

