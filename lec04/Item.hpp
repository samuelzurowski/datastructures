//
//  Item.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include <string>
using namespace std; 

class Item{

protected:
	int key;
	string value; 
	
public:
	Item(){}
	Item(int key, string value):
		key{key}, 
		value{value}
	{}

	int getKey() const{ return key; } 
	string getValue() { return value; }
	bool operator< (const Item& other);
	bool operator== (const Item& other);
};
std::ostream& operator<<(std::ostream& os, const Item& i);



#endif /* Item_hpp */
