//
//  List.hpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/18/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include <iostream>
using namespace std;

class InvalidSlotException{};

template<typename T>
class List {
private:
    T* data;  // ptr arr
    int capacity; // elements it holds
    int slot; // current slot to pushback
    void allocate(int amount);
public:
    List(int capacity=10): capacity{capacity}, slot{0} {
        data = new T[capacity];
    }
    ~List() { delete [] data; }
    int getSlots() const { return slot; }
    int getCapacity() { return capacity; } // get allocated size
    void add(T t);
    const T& operator[](int i) const; // access value with []
    T& operator[](int i);             // modify value with []
    void print();                     // print all values
    void erase(int pos);
};

// ---------------------------------------------------------
// Purpose: To Allow accessing values using [] overloaded
// Allows : To modify values stored in the []
// ---------------------------------------------------------
template<typename T>
T& List<T>::operator[](int i) {
    if(i < 0 || i>= capacity) throw InvalidSlotException();
    return data[i];
}

// ---------------------------------------------------------
// Purpose: To Allow accessing values using [] overloaded
// Allows : To acess values using []
// ---------------------------------------------------------
template<typename T>
const T& List<T>::operator[](int i) const {
    if(i < 0 || i > slot) throw InvalidSlotException();
    return data[i];
}

// ---------------------------------------------------------
// Purpose: To allocate more space if the slot it too large
// Allows : TO increase the size of the array.
// ---------------------------------------------------------
template<typename T>
void List<T>::allocate(int amt) {
    if(amt <= capacity) return;
    
    T* newArr = new T[amt]; // create new array
    for(int i = 0; i < capacity; i++) // copy the elements to new array
        newArr[i] = data[i];
    
    capacity = amt; // set the new capacity
    delete[] data; // delete old arr
    data = newArr; // set Data equal to newArr
}

// ---------------------------------------------------------
// Purpose: Adding elements to the dynamic list
// ---------------------------------------------------------
template<typename T>
void List<T>::add(T t) {
    if(slot >= capacity) allocate(2 * capacity); // if not enough space
    data[slot++] = t;
}

// ---------------------------------------------------------
// Purpose: Mostly used for debugging, printing all elements
// ---------------------------------------------------------
template<typename T>
void List<T>::print() {
    for(int i=0; i< slot; i++)
        cout << data[i] << endl;
}

// ---------------------------------------------------------
// Purpose: Removing a specific element to the list
// Allows : Shifting all the elements over
// ---------------------------------------------------------
template<typename T>
void List<T>::erase(int pos) {
    if(pos >= 0 && pos < getCapacity()) {
        for(int i=pos; i< getCapacity()-1; i++)
            data[i] = data[i+1];
    } slot--;
}


