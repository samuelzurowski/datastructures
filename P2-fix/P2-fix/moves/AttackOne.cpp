//
//  AttackOne.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "AttackOne.hpp"

// execute this attack on the other actor
void AttackOne::execute() {
    damageDone = rand() % (15 - 10 + 1) + 10;
    attackMessage();
    other->hit(damageDone);
}

// revert the attack that happened
void AttackOne::undo() {
    healMessage();
    other->heal(damageDone);
}

// message for executing the attack
void AttackOne::attackMessage() {
    cout << *other << " is hit with " << damageDone << " damage." << endl;
}

// message for undoing the attack
void AttackOne::healMessage() {
    cout << *other << " is healed by " << damageDone << " hp." << endl;
}
