//
//  UnorderedArrayList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "UnorderedArrayList.hpp"
void UnorderedArrayList::MakeEmpty(){
	length = 0;
}

void UnorderedArrayList::PutItem(Item item){
	data[length++] = item;
}

Item* UnorderedArrayList::GetItem(Item item){
	for(int i = 0; i < length; ++i){
		if (data[i] == item) {
			return &data[i]; 
		}
	}
	return nullptr;
}

Item* UnorderedArrayList::GetItem(int key){
	return GetItem(Item(key, "")); 
}

void UnorderedArrayList::DeleteItem(Item item){
	for(int i = 0; i < length; ++i){
		if (data[i] == item)
			data[i] = data[--length];
	}
}

void UnorderedArrayList::ResetList(){
	currentPos = 0;
}

Item* UnorderedArrayList::GetNextItem(){
	if(currentPos < length)
		return &data[currentPos++];
	
	throw "Out of Range";
}

int UnorderedArrayList::GetLength(){
	return length;
}

UnorderedArrayList::~UnorderedArrayList(){
	
}
