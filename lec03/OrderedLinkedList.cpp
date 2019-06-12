//
//  OrderedLinkedList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "OrderedLinkedList.hpp"
void OrderedLinkedList::MakeEmpty(){
	Node* temp = nullptr; 
	while(head != nullptr){
		temp = head;
		head = head->next;
		delete temp;  
	}
	length = 0; 
}

void OrderedLinkedList::PutItem(Item item){
	Node* prev = nullptr; 
	Node* location = head; 
	while(location != nullptr){
		if(location->data < item){
			prev = location; 
			location = location->next; 
		}else{
			break;
		}
	}
	Node* newNode = nullptr;
	try{
		newNode = new Node();
	}catch(std::bad_alloc){
		full = true; 
		return; 
	}
	newNode->data = item; 
	if(prev == nullptr){	// Adding to beginning of the list
		newNode->next = head; 
		head = newNode;
	}else{
		newNode->next = location; 
		prev->next = newNode; 
	}
	length++;
}

Item* OrderedLinkedList::GetItem(Item item){
	Node* temp = head;
	while(temp != nullptr){
		if(item == temp->data){
			item = temp->data; 
			return &temp->data;
		}else if(item < temp->data){
			return nullptr; 
		}
		temp = temp->next; 
	} 
	return nullptr;
}

void OrderedLinkedList::DeleteItem(Item item){
	if(head == nullptr)
		return; 

	Node* temp;
	if(head->data == item){
		temp = head->next;
		delete head; 
		head = temp;
		length--;  
	}else{
		temp = head; 
		while(temp->next != nullptr){
			if(temp->next->data == item){
				Node* temp2 = temp->next; 
				temp->next = temp->next->next; 
				delete temp2; 
				length--; 
				return; 
			}else if(item < temp->next->data){
				return; 
			}
			temp = temp->next;
		}
	}
}

void OrderedLinkedList::ResetList(){
	currentPos = nullptr;
}

Item* OrderedLinkedList::GetNextItem(){
	if(currentPos == nullptr)
		currentPos = head; 
	else
		currentPos = currentPos->next; 

	return &currentPos->data; 
}

int OrderedLinkedList::GetLength(){
	return length;
}

OrderedLinkedList::~OrderedLinkedList(){
	MakeEmpty(); 
}

bool OrderedLinkedList::IsFull(){
	return full; 
}
