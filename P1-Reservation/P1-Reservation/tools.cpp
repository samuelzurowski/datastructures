//
//  tools.cpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/19/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "tools.hpp"

// --------------------------------------------------------------------------
// Function: inputDouble
// Params: variable double ref and the message and error message
// return: void
void inputDouble(double& var, string msg, string errmsg) {
    cout << msg;
    for(;;) {
        cin >> var;
        if(cin.fail() || (var < 0)) {
            cin.clear(); // clear the stream
            // used to throw away input in the stream up to newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << errmsg << endl; // error message
            cout << msg; // print the message again
            continue; // gets input again
        } else break;
    }
}

// --------------------------------------------------------------------------
// Function: Menu Choice
// Params: variable char ref and the message
// return: void
void menuChoice(char& var, string msg) {
    for(;;) {
        string s;
        cout << msg;
        cin >> s;
        if(s.length() > 1) { // used so we can validate the length
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Please Enter Only One Character" << endl;
            continue;
        } var = *s.c_str(); // the char
        break;
    }
}

// --------------------------------------------------------------------------
// Function: get a istring
// Params: variable referencing and the message
// return: void
void inputString(string& var, string msg) {
    cout << msg;
    cin >> ws; //to make sure we don't lose first character and get whole line
    getline(cin, var); // including spaces.
    cin.clear(); // clear cin
}

// --------------------------------------------------------------------------
// Function: get a integer input
// Params: variable referencing and the message, and error message
// return: void
void inputInteger(int& var, string msg, string errmsg) {
    cout << msg;
    while(1) {
        cin >> var;
        if(cin.fail() || (var < 0)) {
            cin.clear(); // clear the stream
            // used to throw away input in the stream up to newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << errmsg << endl; // error message
            cout << msg; // print the message again
            continue; // gets input again
        } else break;
    }
}

// --------------------------------------------------------------------------
// Function: list header for cars list
void listHeader() {
    cout << right << setw(7) << "Make" <<setw(16) << "MODEL" << setw(10)
    << "Type" << setw(17) << "Price/Day" << setw(18) << "License Plate"
    << endl;
    
    cout << right << setw(7) << "----" <<setw(16) << "-----" << setw(10)
    << string(4, '-') << setw(17) << string(9, '-') << setw(18)
    << string(13, '-') << endl;
}

// --------------------------------------------------------------------------
// Function: list header for reserved list
void reservedHeader() {
    cout << right << setw(7) << "NAME" << setw(13) << "Make" <<setw(16)
    << "MODEL" << setw(10) << "Type" << setw(17) << "Price/Day" << setw(18)
    << "License Plate" << endl;
    
    cout << right << setw(7) << "----" << setw(13) << "----" <<setw(16)
    << "-----" << setw(10) << string(4, '-') << setw(17) << string(9, '-')
    << setw(18) << string(13, '-') << endl;
}
