#include <iostream>
#include <vector>
#include "people/Actor.hpp"
#include "moves/AttackOne.hpp"
#include "manager/MoveManager.hpp"
using namespace std;


int main(void){
	MoveManager mgr = MoveManager();
	srand (time(NULL));
	Knight p1 = Knight(100);
	Ghost p2 = Ghost(100);
	p1.doMove(&mgr, ATTACK_ONE, &p2);
	
	return 1;
}