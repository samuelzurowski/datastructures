//
//  Item.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "Item.hpp"

std::ostream& operator<<(std::ostream& os, const Item& i){
	os << "Item: [" << i.getKey() << "]";
	return os;
}

bool Item::operator< (const Item& other){
	return key < other.key; 
}

bool Item::operator== (const Item& other){
	return key == other.key; 
}