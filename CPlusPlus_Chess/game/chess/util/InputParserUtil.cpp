//
//  InputParserUtil.cpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 10/1/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#include "InputParserUtil.hpp"


#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

void ParseInput(string input){
    
    /// 1. Check for delimeter in input
    ///     If delimeter not present, return failure
    /// 2. Get start value before delimeter
    /// 3. Get end Value after delimeter
    /// 4. Convert start value into board[][] coordinates
    ///     check for delimeter
    ///     get first value
    ///     convert to int
    ///         if not convertable, send error
    ///     get second value
    ///     convert to int
    ///         if not convertable, send error
    /// 4. Convert end value into board[][] coordinates
    /// 5. Get CHESS PIECE at start coordinate
    /// 5. Set start coordinate to EMPTY
    /// 6. Set end Coordinate to CHESS PIECE
    /// 7.
    
    
}


vector<string> delineateString(string line, char delimeter){
      
    // Vector of string to save tokens
    vector <string> tokens;
      
    // stringstream class check1
    std::stringstream check1(line);
      
    string intermediate;
      
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, delimeter))
    {
        tokens.push_back(intermediate);
    }
      
    // Printing the token vector
//    for(int i = 0; i < tokens.size(); i++)
//        cout << tokens[i] << '\n';
//    
    return tokens;
}
