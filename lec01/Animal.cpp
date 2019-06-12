//
//  Animal.cpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/18/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "Animal.hpp"
using namespace std;

Animal::Animal(string name):name{name}{
	id = ++lastId; 
	cout << "Animal id: " << id << endl;
}
	
Animal::~Animal(){
	cout << "Animal destructor" << endl;
}
	
string Animal::getName(){
	return name;
}

int Animal::lastId = 10000; 
	
	
