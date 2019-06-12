//
//  Runner.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "Runner.hpp"

// Default Constructor for Runner that serializes the time
Runner::Runner() {
    time_t seconds;
    time(&seconds);
    srand((unsigned)seconds);
}

// List the Welcome message
void Runner::banner() {
    string bar = "───────────────────────────────────────────";
    string tLeft = "┌"; string tRight = "┐\n";
    string bLeft = "└"; string bRight = "┘\n";
    
    cout << tLeft << bar << tRight;
    cout << "│\tWelcome to Battle Simulator\t    │\n";
    cout << "│\tCreated By Samuel Zurowski\t    │\n";
    cout << bLeft << bar << bRight;
}

// List the Options of actors that can be choosen
void actorOptions() {
    cout << "Select a player:"  << endl;
    cout << "1) Ghost"          << endl;
    cout << "2) Knight"         << endl;
    cout << "3) Warrior"        << endl;
    cout << MSG;
}

/**
    Start the match of the Runner Class
    Checks if they have used prompted first
    If they didnt it cannot start the match
 */
void Runner::startMatch() {
    if(!canStart()) return;
    
    showActors();
    for(;;) {
        matchChoice();
        doOption();
    }
}

/**
    Based on the value entered in that specific choice
    1) actor 0 attacks actor 1
    2) actor 1 attacks actor 0
    3) undo the last move
 */
void Runner::doOption() {
    switch(choice) {
        case 1:
            actors[0]->doMove(&manager, actors[1]);
            break;
        case 2:
            actors[1]->doMove(&manager, actors[0]);
            break;
        case 3:
            manager.undoMove();
            break;
    }
    if(!actors[0]->isDead()) {
        cout << "You Lost D: " << endl;
        playOption();
        prompted = 0;
    } 
    else if(!actors[1]->isDead()) {
        cout << "You Won :D " << endl;
        playOption();
        prompted = 0;
    }
    showResults();
}

// Choose to continue playing or quit the game
void Runner::playOption() {
    cout << "Continue Playing?" << endl;
    cout << "1) Yes"            << endl;
    cout << "2) No"             << endl;
    
    cout << MSG;
    inputValidation(choice, 1, 2);
    
    if(choice == 2) abort();
    else {
        manager.clear();
        actors.clear();
        prompt();
    }
}

// Exits the Program
void Runner::abort() {
    cout << "Thank you for using Battle Simulator" << endl;
    cout << "Exiting..."                           << endl;
    exit(1);
}

// Checks if they can start the match yet
bool Runner::canStart() {
    if(prompted) return true;
    cout << "Match must be prompted first" << endl;
    return false;
}

// Choosing options while game is running
void Runner::matchChoice() {
    cout << "1) P1 -> P2" << endl;
    cout << "2) P2 -> P1" << endl;
    cout << "3) Undo" << endl;
    cout << MSG;
    inputValidation(choice, 1, 3);
}

/**
    Prompt the users for choosing the actors they want
    once this is done they can use startMatch
 */
void Runner::prompt() {
    for(int i = 0; i < 2; i++){
        actorOptions();
        inputValidation(choice, 1, 3);
        addActor(choice);
    } prompted = true;
    cout << BEGIN_MATCH << endl;
}
