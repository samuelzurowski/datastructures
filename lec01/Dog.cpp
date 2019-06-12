//
//  Dog.cpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "Dog.hpp"
Dog::Dog(std::string name, std::string coat): Animal(name), coat{coat}{
	std::cout << "Dog constructor" << endl;
	toys.push_back(new Toy(ToyType::BALL));
	toys.push_back(new Toy(ToyType::STUFFED));
}

void Dog::speak(){
	std::cout << name << ": " << "Bark!" << std::endl;
}

Dog::~Dog(){
	cout << "Dog destructor" << endl;
	for(auto t: toys){
		delete t;
	}
}
