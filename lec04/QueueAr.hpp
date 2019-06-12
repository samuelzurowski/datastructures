#pragma once
#include <iostream>
#include "Queue.hpp"
#define MAX_QUEUE_LENGTH 100
class QueueAr : public Queue
{
  private:
    int front;
    int rear;
    int maxLength;
    Item *items;

  public:
    QueueAr() : maxLength{MAX_QUEUE_LENGTH}{
        items = new Item[++this->maxLength]; // Add extra space for reserve
        front = maxLength - 1;
        rear = maxLength - 1;
    }
    QueueAr(int maxLength) : maxLength{maxLength}{
        items = new Item[++this->maxLength]; // Add extra space for reserve
        front = maxLength - 1;
        rear = maxLength - 1;
    }
    void MakeEmpty();
    void Enqueue(Item item);
    Item& Dequeue();
    bool IsEmpty();
    bool IsFull();
    Item& Front(); 

    ~QueueAr() { delete[] items; }
};