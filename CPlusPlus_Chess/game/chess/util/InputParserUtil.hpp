//
//  InputParserUtil.hpp
//  CPlusPlus_Chess
//
//  Created by Jesus' Blood on 10/1/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//

#ifndef InputParserUtil_hpp
#define InputParserUtil_hpp

#include <stdio.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ParseInput(string input);
void IsValidInput(string input);

vector<string> delineateString(string line, char delimeter);

#endif /* InputParserUtil_hpp */
