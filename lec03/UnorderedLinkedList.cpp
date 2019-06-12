//
//  UnorderedLinkedList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "UnorderedLinkedList.hpp"
void UnorderedLinkedList::MakeEmpty(){
	Node* temp = nullptr; 
	while(head != nullptr){
		temp = head;
		head = head->next;
		delete temp;  
	}
	length = 0; 
}

void UnorderedLinkedList::PutItem(Item item){
	Node* temp = new Node;
	temp->data = item; 
	temp->next = head; 
	head = temp; 
	length++; 
}

Item* UnorderedLinkedList::GetItem(Item item){
	Node* temp = head;
	while(temp != nullptr){
		if(temp->data == item){
			item = temp->data; 
			return &(temp->data);
		}
		temp = temp->next; 
	} 
	return nullptr;
}

void UnorderedLinkedList::DeleteItem(Item item){
	if(head == nullptr)
		return; 

	Node* temp;
	if(head->data == item){
		temp = head->next;
		delete head; 
		head = temp;
		length--; 
		return; 
	}
	temp = head; 
	while(temp->next != nullptr){
		if(temp->next->data == item){
			Node* temp2 = temp->next; 
			temp->next = temp->next->next; 
			delete temp2; 
			length--; 
			return; 
		}
		temp = temp->next;
	}
}

void UnorderedLinkedList::ResetList(){
	currentPos = nullptr;
}

Item* UnorderedLinkedList::GetNextItem(){
	if(currentPos == nullptr)
		currentPos = head; 
	else
		currentPos = currentPos->next; 

	return &(currentPos->data); 
}

int UnorderedLinkedList::GetLength(){
	return length;
}

UnorderedLinkedList::~UnorderedLinkedList(){
	MakeEmpty(); 
}
