//
//  OrderedLinkedList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef OrderedLinkedList_hpp
#define OrderedLinkedList_hpp

#include <iostream>
#include <string>
#include "OrderedList.hpp"
#include "Node.hpp"

class OrderedLinkedList: public OrderedList{
private:
	int length;
	Node* currentPos; 
	Node* head; 
	bool full = false; 

public:
	
	OrderedLinkedList(): currentPos{0}, length{0}{}
	~OrderedLinkedList(); 
	void MakeEmpty();
	void PutItem(Item item);
	Item* GetItem(Item item);
	void DeleteItem(Item item);
	void ResetList();
	Item* GetNextItem();
	int GetLength();
	bool IsFull(); 

};

#endif /* OrderedLinkedList_hpp */
