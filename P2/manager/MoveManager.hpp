#pragma once
#include "../Stack.hpp"
#include <iostream>

using namespace std;

class Actor;
class BattleMove;
class AttackOne;
class AttackTwo;
class Heal;

class MoveManager {
    private:
        Stack<BattleMove*> moves = Stack<BattleMove*>();
    public:
        MoveManager() = default ;
        void undoMove();
        void attackOne(Actor* actor);
        void attackTwo(Actor* actor);
        void heal(Actor* actor);
};
