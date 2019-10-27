//
//  ChessRulesService.cpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 10/26/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#include "ChessRulesService.hpp"


bool PlayerOwnsPiece(string chessPiece, int player){
    //cout << "\nPlayer Owns Piece: " << ((int)chessPiece.at(0) == player) << "\n";
    return ((int)chessPiece.at(0) - '0') == player;
}
bool CoordinatesAreNotEmpty(string chessPiece){
    cout << "CoordinatesNotEmpty: " << (chessPiece != CHESS_EMPTY);
    return chessPiece != CHESS_EMPTY;
}
bool CoordinatesNotOutOfBounds(int x, int y){
    cout << "CoordinatesNotOutOfBounds: " << (x <= BOARD_Y && y <= BOARD_X);
    return x < BOARD_Y && y < BOARD_X && x >= 0 && y >= 0;
}
