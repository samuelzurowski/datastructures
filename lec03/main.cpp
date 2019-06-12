//
//  main.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include <iostream>
#include "UnorderedArrayList.hpp"
#include "UnorderedLinkedList.hpp"
#include "OrderedArrayList.hpp"
#include "OrderedLinkedList.hpp"


void TestUnorderedList(UnorderedList* ul){
	cout << ul->GetLength() << " should be 0" << endl; 
	auto v = {1, 5, 2, 12, 13, 9};
	for(auto i : v) ul->PutItem(Item(i, ""));
	cout << *ul << " should contain: 1, 2, 5, 9, 12, 13" << endl;
	
	auto i = ul->GetItem(Item(14, "")); 
	if (i != nullptr)
		cout << *i;
	else
		cout << "Not Found";
	cout << "Should be Not Found" << endl;

	i = ul->GetItem(Item(12, "")); 
	if (i != nullptr)
		cout << *i;
	else
		cout << "Not Found";
	cout << " should be found (12)" << endl;

	ul->DeleteItem(Item(1, ""));
	ul->DeleteItem(Item(12, "")); 
	cout << *ul << " should contain: 2, 5, 9, 13" << endl;
	ul->MakeEmpty(); 
	cout << ul->GetLength() << " should be 0" << endl; 
	cout << "-----------------------------" << endl << endl;
}

void TestOrderedList(OrderedList* ol){
	cout << ol->GetLength() << " should be 0" << endl; 
	auto v = {1, 5, 2, 12, 13, 9};
	for(auto i : v) ol->PutItem(Item(i, ""));
	cout << *ol << " should be: 1, 2, 5, 9, 12, 13" << endl;

	auto i = ol->GetItem(Item(14, "")); 
	if (i != nullptr)
		cout << *i;
	else
		cout << "Not Found";
	cout << "Should be Not Found" << endl;

	i = ol->GetItem(Item(12, "")); 
	if (i != nullptr)
		cout << *i;
	else
		cout << "Not Found";
	cout << " should be found (12)" << endl;

	ol->DeleteItem(Item(1, ""));
	ol->DeleteItem(Item(12, "")); 
	cout << *ol << " should be: 2, 5, 9, 13" << endl;
	ol->MakeEmpty(); 
	cout << ol->GetLength() << " should be 0" << endl; 
	cout << "-----------------------------" << endl << endl;;
}

int main(int argc, const char * argv[]) {
	cout << "Unordered Array List:" << endl << endl;
	auto ual = new UnorderedArrayList();
	TestUnorderedList(ual); 
	delete ual; 

	cout << "Unordered Linked List:" << endl << endl;
	auto ull = new UnorderedLinkedList();
	TestUnorderedList(ull); 
	delete ull; 
	
	cout << "Ordered Array List:" << endl << endl;
	auto oal = new OrderedArrayList(); 
	TestOrderedList(oal); 
	delete oal; 
	
	cout << "Ordered Linked List:" << endl << endl;
	auto oll = new OrderedLinkedList(); 
	TestOrderedList(oll); 
	delete oll; 
	return 0;
}
