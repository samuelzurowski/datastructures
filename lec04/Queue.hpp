#pragma once
#include <iostream>
#include "Item.hpp"

class QueueFullException{};
class QueueEmptyException{};

class Queue{
public:
    virtual void MakeEmpty()=0;
    virtual void Enqueue(Item item)=0; 
    virtual Item& Front()=0;
    virtual Item& Dequeue()=0;
    virtual bool IsEmpty()=0;
    virtual bool IsFull()=0;
    virtual ~Queue(){};
};

ostream& operator<<(ostream& os, Queue& o);
