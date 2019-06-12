#pragma once
#include "Stack.hpp"
#include "Item.hpp"
#include "Node.hpp"
#define MAX_LENGTH 100

class StackLi: public Stack{
private:
    Node* top; 

public:
    StackLi(){
        top = nullptr; 
    }
 
    void Push(Item item); 
    Item& Top(); 
    void Pop(); 
    bool IsFull() const; 
    bool IsEmpty() const; 
    ~StackLi();
};


