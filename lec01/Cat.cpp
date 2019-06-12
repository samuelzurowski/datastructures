//
//  Cat.cpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "Cat.hpp"
Cat::Cat(std::string name, std::string attitude): Animal(name), attitude{attitude}
{
	std::cout << "Cat constructor" << std::endl;
}
void Cat::speak(){
	std::cout << name << ": " << "Meow!" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor" << std::endl;
}
