//
//  Dog.hpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <iostream>
#include <vector>
#include <string>
#include "Toy.hpp"
#include "Animal.hpp"

class Dog: public Animal{
private:
	std::string coat;
	std::vector<Toy*> toys;
public:
	Dog(std::string name, std::string coat);
	void speak();
	~Dog();
};

#endif /* Dog_hpp */
