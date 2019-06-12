#pragma once
#include "BattleMove.hpp"

class Heal : public BattleMove {
    private:
        int healAmount;
    public:
        Heal(Actor* actor): BattleMove(actor, nullptr){}
        void execute();
        void undo();  
};