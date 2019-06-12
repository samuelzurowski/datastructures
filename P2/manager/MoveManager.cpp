#include "MoveManager.hpp"
#include "../people/Actor.hpp"
#include "../moves/AttackOne.hpp"
#include "../moves/AttackTwo.hpp"
#include "../moves/Heal.hpp"

void MoveManager::attackOne(Actor* other) {
    AttackOne attackOne = AttackOne(other);
    attackOne.execute();

    moves.Push(&attackOne);
}

// ------
// todo these
void MoveManager::attackTwo(Actor* other) {
    AttackTwo attackTwo = AttackTwo(other);
    attackTwo.execute();
    moves.Push(&attackTwo);
}

void MoveManager::heal(Actor* self) {
    Heal heal = Heal(self);
    heal.execute();
    moves.Push(&heal);
}

void MoveManager::undoMove() {
    moves.Top()->undo();
    moves.Pop();
}