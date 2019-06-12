//
//  AttackTwo.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "AttackTwo.hpp"

// execute this attack on the other actor
void AttackTwo::execute() {
    damageDone = rand() % 26;
    attackMessage();
    other->hit(damageDone);
}

// revert the attack that happened
void AttackTwo::undo() {
    healMessage();
    other->heal(damageDone);
}

// message for executing the attack
void AttackTwo::attackMessage() {
    cout << *other << " is hit with " << damageDone << " damage." << endl;
}

// message for undoing the attack
void AttackTwo::healMessage() {
    cout << *other << " is healed by " << damageDone << " hp." << endl;
}
