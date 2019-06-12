//
//  Animal.hpp
//  Lec1_code
//
//  Created by Eugene Lymar on 1/18/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <iostream>
#include <string>
using namespace std; 
class Animal{
private:
	int id; 

protected:
	string name;
	static int lastId; 

public:
	Animal(string name);
	virtual void speak()=0;
	string getName();
	virtual ~Animal(); 
};

#endif /* Animal_hpp */
