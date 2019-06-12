//
//  BattleMove.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include "../people/Actor.hpp"
#include <random>

class BattleMove {
protected:
    Actor* self;
    Actor* other;
public:
    BattleMove(Actor* self, Actor* other): self(self), other(other){}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void attackMessage() = 0;
    virtual void healMessage() = 0;

};
