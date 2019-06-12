//
//  Heal.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include "BattleMove.hpp"

class Heal : public BattleMove {
private:
    int healAmount;
public:
    Heal(Actor* self): BattleMove(self, nullptr){}
    void execute();
    void undo();
    void attackMessage();
    void healMessage();
};
