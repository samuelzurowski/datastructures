//
//  UnorderedLinkedList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef UnorderedLinkedList_hpp
#define UnorderedLinkedList_hpp

#include <iostream>
#include <string>
#include "UnorderedList.hpp"
#include "Node.hpp"

class UnorderedLinkedList: public UnorderedList{
private:
	int length;
	Node* currentPos; 
	Node* head; 

public:
	
	UnorderedLinkedList(): currentPos{nullptr}, head{nullptr}, length{0}{}
	~UnorderedLinkedList(); 
	void MakeEmpty();
	void PutItem(Item item);
	Item* GetItem(Item item);
	void DeleteItem(Item item);
	void ResetList();
	Item* GetNextItem();
	int GetLength();

};

#endif /* UnorderedLinkedList_hpp */
