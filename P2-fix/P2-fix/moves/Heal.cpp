//
//  Heal.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "Heal.hpp"

// execute this heal on the actor who called it
void Heal::execute() {
    healAmount = rand() % (15 - 10 + 1) + 10;
    healMessage();
    self->heal(healAmount);
}

// revert the heal that happened
void Heal::undo() {
    attackMessage();
    self->hit(healAmount);
}

// message for undoing the heal
void Heal::attackMessage() {
    cout << *self << " is hit with " << healAmount << " damage." << endl;
}
// message for executing the heal
void Heal::healMessage() {
    cout << *self << " is healed by " << healAmount << " hp." << endl;
}
