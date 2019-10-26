//
//  GameEngine.cpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 9/20/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

#include "GameEngine.hpp"
#include "ChessBoardRenderer.hpp"
#include "Constants.hpp"
#include "InputParserUtil.hpp"

using namespace std;


bool didPlayerWin = false;
bool playerEndedTurn = false;
bool goalAccomplished = false;
int actionCount = 0;
int currentPlayer = 1;
int winningPlayer = 0;

void BuildGame(){
    cout << "The Game is being built\n\n";
    cout << "The Game has been built!\n\n";
    
}

void StartGame(){
    currentPlayer = PLAYER_ONE;
    BuildInitialBoard(GetCurrentPlayer());
    cout << "The Game is has started!\n\n";
}
int SwitchPlayerTurn(){
    
    if(currentPlayer == PLAYER_ONE){
        currentPlayer = PLAYER_TWO;
    }else{
        currentPlayer = PLAYER_ONE;
    }

    cout << "Switching players...\n\n";
    
    return currentPlayer;
}

int GetCurrentPlayer(){
    
    return currentPlayer;
}

void resetVariables(){
    actionCount = 1;
    playerEndedTurn = false;
}

void PlayerTurnStart(){

    string decision;
    usleep(1000000);
    
    cout << "Player " << GetCurrentPlayer() << "'s turn\n\n";
    resetVariables();
    
    bool validMoveSelected = false;
    bool moveWasMade = false;
    
    while(!validMoveSelected || !moveWasMade){
        usleep(1000000);
        
        RenderBoard(currentPlayer);
        //TODO: Place in ChessPlayerAction class -
        cout << "What will you do?\n";
        cin >> decision;
        
        if(decision == "end"){
            usleep(1000000);
            validMoveSelected = true;
            moveWasMade = true;
            
            cout << "Player " << GetCurrentPlayer() << " will not take any more moves.\n\n";
            EndTurn();
        }
        else if(decision == "more"){
            usleep(1000000);
            actionCount++;
            validMoveSelected = true;
            moveWasMade = true;
            cout << "Player " << GetCurrentPlayer() << " will take another action!\n\n";
        }else if(decision == "move"){
            usleep(1000000);
            validMoveSelected = true;
            moveWasMade = true;
            cout << "Player " << GetCurrentPlayer() << " has selected to move!\n\n";
            
        }else if(decision == "view"){
            usleep(1000000);
            validMoveSelected = true;
            cout << "Showing Available Moves...";
            moveWasMade = false;
            
        }
        else if(!validMoveSelected){
            usleep(1000000);
            cout << "Invalid move selected. Try again.\n";
        }
        
    }
    
}


void PlayerMoveStart(){

    usleep(1000000);
    
    cout << "Player " << GetCurrentPlayer() << "  has started to move...\n\n";
    
}
void PlayerMoveAction(){

    bool validMoveSelected = false;
    string winningMove = "";
    while(!validMoveSelected && !WinConditionWasMet()){
        usleep(1000000);
        string action;

        RenderBoard(currentPlayer);
        cout << "Give me an action...\n";
        cin >> action;
        cout << "Player " << GetCurrentPlayer() << " has selected an action!\n\n";

        //TODO: Put this in a ChessPieceActions class
        if(action == "act"){
            usleep(1000000);
            
            string selectedPieceCoordinatesString = "";
            vector<int> selectedPieceCoordinates;
            vector<int> destinationCoordinates;
            
            cout << "Select Piece coordinates (x,y): ";

            cin >> selectedPieceCoordinatesString;
            //TODO: Convert Selected coordinates into int
            selectedPieceCoordinates = convertCoordinatesToInt(selectedPieceCoordinatesString);
            //TODO: if Player selected valid piece
                //playerOwnsPiece()
                //coordinatesAreNotEmpty()
            if(true){
                //TODO: Show selected piece valid moves
                string destinationCoordinatesString = "";
                cout << "Select Destination coordinates (x,y): ";
                cin >> destinationCoordinatesString;
                
                destinationCoordinates = convertCoordinatesToInt(destinationCoordinatesString);
                
                //TODO: if Move is valid
                    //moveDestinationMatchesPieceMovementPattern()
                    //coordinateNotOutOfBounds()
                if(true){
                    //TODO: Move piece from selectedPieceCoordinates to destinationCoordinates
                    testMovePiece(selectedPieceCoordinates, destinationCoordinates);
                    
                    cout << "Moving piece from " << selectedPieceCoordinatesString << " to " << destinationCoordinatesString;
                    //TODO: Determine if win condition was met
                        //wasWinConditionMet(int board)
                }
                
            }
            //if moveCoordinates are valid...
            
            RenderBoard(currentPlayer);
            validMoveSelected = true;
            
            cout << "Player " << GetCurrentPlayer() << " made a decisive action!!\n\n";
            usleep(1000000);
            cout << "Is this the winning move?\n";
            cin >> winningMove;
            
            if(winningMove == "yes"
               || winningMove == "y"){
                goalAccomplished = true;
            }else if (winningMove == "no"
                      || winningMove == "n"){
                goalAccomplished = false;
            }else{
                validMoveSelected = false;
                cout << "Invalid action selected. Try again.\n\n";
            }
        }
        else{
            validMoveSelected = false;
            cout << "Invalid move selected. Try again.\n";
        }
    }

    actionCount--;
    
    if(actionCount > 0 && !WinConditionWasMet()){
         cout << "Player " << GetCurrentPlayer() << " has " << actionCount << " actions left!\n\n";
    }
    
}
bool PlayerStillHasActions(){
    return actionCount > 0;
}
void PlayerMoveEnd(){

    usleep(1000000);
    RenderBoard(currentPlayer);
    cout << "Player " << GetCurrentPlayer() << "  has ended the move. \n\n";
    if(actionCount <= 0){
        EndTurn();
    }
    if(goalAccomplished){
        TriggerWinCondition(GetCurrentPlayer());
    }
}

bool PlayerTurnHasEnded(){
    return playerEndedTurn;
}
void EndTurn(){
    playerEndedTurn = true;
    
}
void PlayerTurnEnd(){

    usleep(1000000);
    cout << "Player " << GetCurrentPlayer() << "'s turn has ended. \n\n";
    if(!goalAccomplished){
        SwitchPlayerTurn();
    }
}

void TriggerWinCondition(int theWinningPlayer){

    winningPlayer = theWinningPlayer;
    didPlayerWin = true;
}
bool WinConditionWasMet(){
    
    return didPlayerWin;
}
void PlayerWin(){
    
    usleep(2000000);
    cout << "\n_______________________________________\n\n ";
    cout << "We have a winner...\n\n";
    cout << "\n_______________________________________\n\n ";
    usleep(1000000);
    cout << "...\n\n";
    usleep(1000000);
    cout << ".......\n\n";
    usleep(1000000);
    cout << "............\n\n";
    usleep(1000000);
    cout << "Player " << winningPlayer << " has won the game!!";
}
void EndGame(){
    cout << "\n_______________________________________\nGame has ended. Thanks For Playing!";
}




bool validResponseInput(string inputString, string listOfValidMoves[], int maxSize){
    
    for(int i = 0; i < maxSize; i++){
        if(listOfValidMoves[i] == inputString){
            return true;
        }
    }
    return false;
}

vector<int> convertCoordinatesToInt(string coordinates){
    vector<int> intCoordinates;
    
    //parse coordinates string for numbers into array; coordinates = string of 2 numbers separated by comma, no spaces
    vector<string> stringCoordinates = delineateString(coordinates, ',');

    //for each coordinate,
    for(int i=0; i < stringCoordinates.size(); i++){
        int coordinateValue = std::stoi(stringCoordinates[i]);
        cout << "Received coordinate value to_int: " << coordinateValue;
        intCoordinates.push_back(coordinateValue);
        
    }
        //convert To Int
        //PushBack to intCoordinates vector
    
    return intCoordinates;
}
