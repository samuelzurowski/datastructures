#pragma once
#include "../manager/MoveManager.hpp"
#include "../types/enum.hpp"

#include <iostream>
#include <vector>
using namespace std;

class MoveManager;

class Actor {
    private:
        bool alive = true;
    protected:
        int health;
        string type;
        vector<moveType> moves;
    public:
		Actor(int h, string type): health(h), type(type) {} 
		void doMove(MoveManager* mgr, moveType m, Actor* other);
		void hit(int amount);
		void heal(int amount);
		void getMoves();	//vector of MoveTypes
		bool isDead() { return alive; }
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