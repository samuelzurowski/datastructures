#pragma once
#include "BattleMove.hpp"

class AttackTwo : public BattleMove {
    private:
        int damageDone;
    public:
        AttackTwo(Actor* actor): BattleMove(nullptr, actor){}
        void execute();
        void undo();  
};