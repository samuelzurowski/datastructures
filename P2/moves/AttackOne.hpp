#pragma once
#include "BattleMove.hpp"
#include "../people/Actor.hpp"

class AttackOne : public BattleMove {
    private:
        int damageDone;
    public:
        AttackOne(Actor* actor): BattleMove(nullptr, actor){}
        void execute() {
            damageDone = rand() % (15 - 10 + 1) + 10;
            other->hit(damageDone);
        }
        void undo() {
            other->heal(damageDone);
        }
};