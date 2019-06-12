//
//  Actor.hpp
//  P2
//
//  Created by Samuel Zurowski on 4/6/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include "../manager/MoveManager.hpp"
#include "../types/enum.hpp"
#include "../tools/TypeValidation.hpp"

#include <iostream>
#include <vector>
using namespace std;

class MoveManager;

class Actor {
private:
    bool alive = true;
    moveType pickRandom() { return moves[rand() % 2]; } // randomly choose a move
protected:
    int health;
    string type;
    vector<moveType> moves;
public:
    Actor(int h, string type): health(h), type(type) {}
    void doMove(MoveManager* mgr, Actor *actor);
    void hit(int amount);
    void heal(int amount);
    void optionSelected(moveType m);
    bool isDead() { return alive; }
    friend ostream& operator<<(ostream& out, const Actor &actor);
};

class Ghost : public Actor {
public:
    Ghost(int h): Actor(h, "Ghost") {
        moves.push_back(ATTACK_ONE);
        moves.push_back(HEAL);
    }
};

class Knight : public Actor {
public:
    Knight(int h): Actor(h, "Knight") {
        moves.push_back(ATTACK_TWO);
        moves.push_back(HEAL);
    }
};

class Warrior : public Actor {
public:
    Warrior(int h): Actor(h, "Warrior") {
        moves.push_back(ATTACK_ONE);
        moves.push_back(ATTACK_TWO);
    }
};
