#include "AttackTwo.hpp"
void AttackTwo::execute() {
    damageDone = rand() % 26;
    other->hit(damageDone);
}

void AttackTwo::undo() {
    other->heal(damageDone);
}
