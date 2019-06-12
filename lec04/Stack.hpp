#pragma once
#include "iostream"
#include <string>
#include "Item.hpp"

struct StackFullException{
    std::string message;
    StackFullException():message{"Stack is full"}{}
};

struct StackEmptyException{
    std::string message; 
    StackEmptyException():message{"Stack is empty"}{}
};

class Stack{
    public:
        virtual void Push(Item item)=0;
        virtual void Pop()=0;
        virtual Item& Top()=0; 
        virtual bool IsEmpty() const =0;
        virtual bool IsFull() const =0;
        virtual ~Stack(){};

};

ostream& operator<<(ostream& os, Stack& o);
