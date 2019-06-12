//
//  main.cpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/18/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	vector<Animal*> animals;
	animals.push_back(new Dog("Fido", "black"));
	animals.push_back(new Cat("Garfield", "lazy"));

	for(auto a: animals)
		a->speak();
	
	for(auto a: animals)
		delete a;
	
	return 0;
}
