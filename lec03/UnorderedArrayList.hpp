//
//  UnorderedArrayList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <iostream>
#include <string>
#include "UnorderedList.hpp"

class UnorderedArrayList: public UnorderedList{
private:
	int currentPos;
	int length;
	Item data[MAX_ELEMS];

public:
	UnorderedArrayList():currentPos{-1}, length{0}{}; 	
	void MakeEmpty();
	void PutItem(Item item);
	Item* GetItem(Item item);
	Item* GetItem(int key);
	void DeleteItem(Item item);
	void ResetList();
	Item* GetNextItem();
	int GetLength();
	~UnorderedArrayList(); 

};

#endif /* ArrayList_hpp */
