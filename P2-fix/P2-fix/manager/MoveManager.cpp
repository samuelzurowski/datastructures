//
//  MoveManager.cpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//


#include "MoveManager.hpp"
#include "../people/Actor.hpp"
#include "../moves/AttackOne.hpp"
#include "../moves/AttackTwo.hpp"
#include "../moves/Heal.hpp"

// save the attack one called
void MoveManager::attackOne(Actor* other) {
    AttackOne *attackOne = new AttackOne(other);
    attackOne->execute();
    
    moves.Push(attackOne);
}

// save the attack two called
void MoveManager::attackTwo(Actor* other) {
    AttackTwo *attackTwo = new AttackTwo(other);
    attackTwo->execute();
    
    moves.Push(attackTwo);
}

// stack clear
void MoveManager::clear() {
    moves.MakeEmpty();
}
// save the heal called
void MoveManager::heal(Actor* self) {
    Heal *heal = new Heal(self);
    heal->execute();
    
    moves.Push(heal);
}

// revert the last move done
void MoveManager::undoMove() {
    try {
        moves.Top()->undo();
        moves.Pop();
    } catch(StackEmptyException e) {
        cout << "No moves to undo." << endl;
    }
}
