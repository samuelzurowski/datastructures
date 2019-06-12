//
//  TypeValidation.hpp
//  P2-fix
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//
#pragma once

#define ERR_MSG "Invalid Value Enter, Try Again."
#define MSG "Enter Option: "

#include <iostream>
#include <limits>

using namespace std;
/**
    Validates the Input that is entered into the stream.
 
    @param var that is going to be modified
    @param min the smallest value that var can be
    @param max the max value that var can be
 */
template <typename T>
void inputValidation(T& var, T min, T max) {
    for(;;) {
        cin >> var;
        if(cin.fail() || var < min || var > max ) {
            cin.clear(); // clear the stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << ERR_MSG << endl; // error message
            cout << MSG; // print the message again
            continue; // gets input again
        } else break;
    }
}

