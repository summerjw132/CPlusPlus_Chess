//
//  ChessBoardRenderer.hpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 1/1/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#ifndef ChessBoardRenderer_hpp
#define ChessBoardRenderer_hpp

#include <stdio.h>
#include "constants/Constants.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void InitBoard();
void BuildInitialBoard( int currentPlayer); // Builds out the initial board
void RenderBoard( int currentPlayer); //Re-renders the board to the view after updates
string GetCellFromBoard(int x, int y);
static void buildLineBreak(int row);

void renderChessBoard(int currentPlayer, int board[BOARD_X][BOARD_Y]);
void renderChessPieces(int currentPlayer, int board[BOARD_X][BOARD_Y]);
string buildPlayerChessPiece(string chessPiece, int x);
void testMovePiece(vector<int> selectedPieceCoordinates, vector<int> destinationCoordinates );
void buildColumnIndexes(int columnCount);



//TODO: Refactor with these methods
int getPlayerOneFrontLine();
int getPlayerOneBackLine();
int getPlayerTwoFrontLine();
int getPlayerTwoBackLine();
#endif /* ChessBoardRenderer_hpp */



