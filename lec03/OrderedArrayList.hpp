//
//  OrderedArrayList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef OrderedArrayList_hpp
#define OrderedArrayList_hpp

#include <iostream>
#include <string>
#include "OrderedList.hpp"

class OrderedArrayList: public OrderedList{
private:
	int currentPos;
	int length;
	Item data[MAX_ELEMS];

public:
	OrderedArrayList(): currentPos{0}, length{0}{}
	void MakeEmpty();
	void PutItem(Item item);
	Item* GetItem(Item item);
	void DeleteItem(Item item);
	void ResetList();
	Item* GetNextItem();
	int GetLength();

};

#endif /* OrderedArrayList_hpp */
