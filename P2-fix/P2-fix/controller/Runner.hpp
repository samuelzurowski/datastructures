//
//  Runner.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once

#include "../manager/MoveManager.hpp"
#include <iomanip>
#include "../people/Actor.hpp"
#include "../tools/TypeValidation.hpp"

#define BEGIN_MATCH "Beginning match!"

class Runner {
private:
    vector<Actor*> actors;
    MoveManager manager;
    int choice;
    bool prompted = false;
    
    /**
        Add a actor that will be used to the actors
        @param choice the choice of the actor
     */
    void addActor(int choice) {
        if(choice == 1) actors.push_back(new Ghost(100));
        if(choice == 2) actors.push_back(new Knight(100));
        if(choice == 3) actors.push_back(new Warrior(100));
        cout << "You selected: " << choice << endl;
    }
    
    // lists the actors for the start
    void showActors() {
        for(auto val: actors)
            cout << *val << endl;
        cout << string(40, '-') << endl;
    }
    
    // after an attack or heal is executed
    void showResults() {
        cout << "[Player: " << *actors[0]
        << "][Opponent: "   << *actors[1] << "]\n";
    }
public:
    void playOption();
    bool canStart();
    void banner();
    void matchChoice();
    Runner();
    void prompt();
    void startMatch();
    void doOption();
    void abort();
};
