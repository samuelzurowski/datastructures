//
//  Actor.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "Actor.hpp"
/**
    Operator overload the << to allow printing of the actor
    @param out the stream the text will be sent to
    @param actor that is being reference
    @return out the data sent into the ostream
 */
ostream& operator<<(ostream& out, const Actor &actor) {
    return out << actor.type << ", (" << actor.health << ")";
}

/**
    Prints the info of what the attack used for a move
    @param m enum of attack types
 */
void Actor::optionSelected(moveType m) {
    if(m == ATTACK_ONE) cout << " used: AttackOne"  << endl;
    if(m == ATTACK_TWO) cout << " used: AttackTwo"  << endl;
    if(m == HEAL)       cout << " used: Heal"       << endl;
}

/**
    Execute a move
    @param mgr the class that manages every move done.
    @param actor who you are possibly executing the attack on
 */
void Actor::doMove(MoveManager* mgr, Actor *actor) {
    moveType m = pickRandom();
    if(m == ATTACK_ONE) {
        cout << *this << " used: AttackOne" << endl;
        mgr->attackOne(actor);
    }
    else if (m == ATTACK_TWO) {
        cout << *this << " used: AttackTwo" << endl;
        mgr->attackTwo(actor);
    }
    else if(m == HEAL) {
        cout << *this << " used: Heal"      << endl;
        mgr->heal(this);
    } 
    else cout << "Error on move try again..";
}

/**
    Heal a specific Actor
    @param amount how much health they will gain
 */
void Actor::heal(int amount) {
    health += amount;
}

/**
    Hit a specific Actor
    @param amount of health they will lose
 */
void Actor::hit(int amount) {
    health -= amount;
    if(health <= 0) alive = 0;
}
