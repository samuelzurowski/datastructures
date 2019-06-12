//
//  Toy.hpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/19/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef Toy_hpp
#define Toy_hpp

#include <iostream>
#include "enums.hpp"

class Toy{
private:
	ToyType type;
public:
	Toy(ToyType type);
	~Toy();
};

#endif /* Toy_hpp */
