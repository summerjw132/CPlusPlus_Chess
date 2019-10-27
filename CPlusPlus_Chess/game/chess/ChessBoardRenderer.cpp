//
//  ChessBoardRenderer.cpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 1/1/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#include "ChessBoardRenderer.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

string board[BOARD_X][BOARD_Y];

void InitBoard(){
    for(int x = 0; x<BOARD_X; x++){
       for(int y = 0; y<BOARD_Y; y++){
           if ( //
                x == BOARD_X-2   ||           //2nd to last row (P1)
                //
                x == BOARD_X - BOARD_X + 1    //second row (P2)
               ){
               
               board[x][y] = buildPlayerChessPiece(CHESS_PAWN, x);
           }else if(x == BOARD_X-1 ||        //last row (P1)
                    x == BOARD_X - BOARD_X     //firstRow (P2)
                    ){
               switch (y) {
                   case 0:
                       board[x][y] = buildPlayerChessPiece(CHESS_BISHOP, x);
                       break;
                   case 1:
                       board[x][y] = buildPlayerChessPiece(CHESS_KNIGHT, x);
                       break;
                   case 2:
                       board[x][y] = buildPlayerChessPiece(CHESS_ROOK, x);
                       break;
                   case 3:
                       board[x][y] = buildPlayerChessPiece(CHESS_QUEEN, x);
                       break;
                   case 4:
                       board[x][y] = buildPlayerChessPiece(CHESS_KING, x);
                       break;
                   case 5:
                       board[x][y] = buildPlayerChessPiece(CHESS_ROOK, x);
                       break;
                   case 6:
                       board[x][y] = buildPlayerChessPiece(CHESS_KNIGHT, x);
                       break;
                   case 7:
                       board[x][y] = buildPlayerChessPiece(CHESS_BISHOP, x);
                       break;
                   default:
                       board[x][y] = buildPlayerChessPiece(CHESS_EMPTY, x);
                       break;
               }
           }else{
               board[x][y] = buildPlayerChessPiece(CHESS_EMPTY, x);
           }
       }
    }
}

void BuildInitialBoard( int currentPlayer){
    InitBoard();
    RenderBoard(currentPlayer);
}

void RenderBoard( int currentPlayer){

    int count = 0;
    cout << "\n\n\n\n";
    cout << "\n\n";
    buildColumnIndexes(BOARD_Y);
    for(int row = 0; row<BOARD_X; row++){
        
        for(int col = 0; col<BOARD_Y; col++){
            count++;
            cout << board[row][col];
            
            if(col < BOARD_X -1){
                cout << "|";          // column boundary
            }else{
                cout << "   " << to_string(row);
            }
        }
        buildLineBreak(row);
    }
    cout << "\n\n";
}


string GetCellFromBoard(int x, int y){
    return board[y][x];
}


static void buildLineBreak(int row) {
    if (row < BOARD_X-1) {
        string lineBreak ="\n";
        for(int i = 0; i < BOARD_Y; i++){
            lineBreak += "--+" ;
        }
        cout << lineBreak  << "\n";}
}



string buildPlayerChessPiece(string chessPiece, int row){
    string playerChessPiece = CHESS_EMPTY;
    
    if(row == BOARD_X - BOARD_X || row == BOARD_X - BOARD_X + 1){
        playerChessPiece = to_string(PLAYER_TWO) + (chessPiece);
        
    }else if(row == BOARD_X-1 || row == BOARD_X-2){
        playerChessPiece = to_string(PLAYER_ONE) + (chessPiece);
        
    }
    return playerChessPiece;
}

void buildColumnIndexes(int columnCount){
    string columnIndexes = "";
    for(int col = 0; col < columnCount; col++){
        columnIndexes += " " + to_string(col) + " ";
        
    }
    cout << columnIndexes << "\n\n";
}

void testMovePiece(vector<int> selectedPieceCoordinates, vector<int> destinationCoordinates ){
    string currentPiece = board[selectedPieceCoordinates[1]][selectedPieceCoordinates[0]];
    board[selectedPieceCoordinates[1]][selectedPieceCoordinates[0]] = CHESS_EMPTY;
    
    board[destinationCoordinates[1]][destinationCoordinates[0]] = currentPiece;
    
}
