//
//  OrderedArrayList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "OrderedArrayList.hpp"
void OrderedArrayList::MakeEmpty(){
	length = 0;
}

void OrderedArrayList::PutItem(Item item){
    int loc = length; 
    while(loc > 0 && item < data[loc-1]){
        data[loc] = data[loc-1];
        loc--;  
    }
    data[loc] = item; 
    length++; 
}

Item* OrderedArrayList::GetItem(Item item){
    // Binary Search
    int first = 0; 
    int last = length - 1; 
    int mid; 

    while(first <= last){
        mid = (first + last) / 2; 
        if(item == data[mid]){
            item = data[mid]; 
            return &data[mid]; 
        }else if(item < data[mid]){
            last = mid - 1; 
        }else{
            first = mid + 1; 
        }
    }
    return nullptr; 
}

void OrderedArrayList::DeleteItem(Item item){
    int i = 0; 
	while (!(data[i] == item)){
        i++;
    }
    for(int j = i + 1; j < length; ++j){
        data[j-1] = data[j];
    }
    length--; 

}

void OrderedArrayList::ResetList(){
	currentPos = 0;
}

Item* OrderedArrayList::GetNextItem(){
	if(currentPos < length)
		return &data[currentPos++];
	
	throw "Out of Range";
}

int OrderedArrayList::GetLength(){
	return length;
}
