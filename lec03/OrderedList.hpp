//
//  OrderedList.hpp
//  OrderedList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef OrderedList_hpp
#define OrderedList_hpp

#define MAX_ELEMS 100

#include <iostream>
#include <string.h>
#include "Item.hpp"

using namespace std;

class OrderedList{
public:
	virtual ~OrderedList(){}; 
	virtual void MakeEmpty()=0;
	virtual void PutItem(Item item)=0;
	virtual Item* GetItem(Item item)=0;
	virtual void DeleteItem(Item item)=0;
	virtual void ResetList()=0;
	virtual Item* GetNextItem()=0;
	virtual int GetLength()=0;
	
};

ostream& operator<<(ostream& os, OrderedList& o);


#endif /* OrderedList_hpp */
