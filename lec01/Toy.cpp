//
//  Toy.cpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "Toy.hpp"

Toy::Toy(ToyType type): type{type}{
	std::cout << "Toy constructor" << std::endl;
}

Toy::~Toy(){
	std::cout << "Toy destructor for:" << type << std::endl;
}
