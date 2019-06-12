//
//  Cat.hpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef Cat_hpp
#define Cat_hpp

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal{
private:
	std::string attitude;
public:
	Cat(std::string name, std::string attitude);
	void speak();
	~Cat();
};
#endif /* Cat_hpp */
