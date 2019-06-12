//
//  MoveManager.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include "../types/Stack.hpp"

class Actor;
class BattleMove;

class MoveManager {
private:
    Stack<BattleMove*> moves = Stack<BattleMove*>(1000);
public:
    MoveManager() = default;
    void clear();
    void undoMove();
    void attackOne(Actor* other);
    void attackTwo(Actor* other);
    void heal(Actor* actor);
};
