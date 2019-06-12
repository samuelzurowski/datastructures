//
//  tools.hpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/19/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void listHeader();
void reservedHeader();
void inputDouble(double& var, string msg, string errmsg);
void menuChoice(char& var, string msg);
void inputString(string& var, string msg);
void inputInteger(int& var, string msg, string errmsg);
