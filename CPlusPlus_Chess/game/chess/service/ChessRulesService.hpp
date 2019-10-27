//
//  ChessRulesService.hpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 10/26/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#ifndef ChessRulesService_hpp
#define ChessRulesService_hpp

#include "Constants.hpp"
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool PlayerOwnsPiece(string chessPiece, int player);
/// Determines whether a given coordinate == CHESS_EMPTY
bool CoordinatesAreNotEmpty(string chessPiece);
/// Determines if a given coordinate is Out Of Bounds
bool CoordinatesNotOutOfBounds(int x, int y);




#endif /* ChessRulesService_hpp */
