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
};
