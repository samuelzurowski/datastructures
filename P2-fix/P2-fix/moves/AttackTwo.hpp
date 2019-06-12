//
//  AttackTwo.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include "BattleMove.hpp"

class AttackTwo : public BattleMove {
private:
    int damageDone;
public:
    AttackTwo(Actor* actor): BattleMove(nullptr, actor){}
    void execute();
    void undo();
    void attackMessage();
    void healMessage();
};
