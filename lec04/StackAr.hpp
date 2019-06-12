#pragma once
#include "Stack.hpp"

#define MAX_STACK_LENGTH 100
class StackAr: public Stack{
private:
    int maxLength; 
    int top; 
    Item * data; 

public:
    StackAr():maxLength{MAX_STACK_LENGTH}{
        data = new Item[maxLength]; 
        top = -1; 
    }
    StackAr(int length):maxLength{length}{
        data = new Item[maxLength];
        top = -1; 
    }
    void Push(Item item); 
    Item& Top(); 
    void Pop(); 
    bool IsFull() const; 
    bool IsEmpty() const; 
    ~StackAr(){  delete[] data; }

};


