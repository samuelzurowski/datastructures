#include "Heal.hpp"
#include "../types/enum.hpp"
void Heal::execute() {
    healAmount = rand() % (15 - 10 + 1) + 10;
    self->heal(healAmount);
}

void Heal::undo() {
    self->hit(healAmount);
}
