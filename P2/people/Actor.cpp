#include "Actor.hpp"

void Actor::doMove(MoveManager* mgr, moveType m, Actor *actor) {
    switch (m) {
        case ATTACK_ONE:
            mgr->attackOne(actor);
            break;
        case ATTACK_TWO:
            mgr->attackTwo(actor);
            break;
        case HEAL:
            mgr->heal(actor);
            break;
        default:
            break;
    }
}

void Actor::heal(int amount) {
    if(health + amount > 100) health = 100;
    else health += amount;
}

void Actor::hit(int amount) {
    health -= amount;
    if(health <= 0) alive = false;
}