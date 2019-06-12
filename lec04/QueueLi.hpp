#include <iostream>
#include "Queue.hpp"
#include "Item.hpp" 
#include "Node.hpp"

class QueueLi: public Queue{
private:
    Node* front; 
    Node* rear; 

public:
    QueueLi(){
        front = nullptr; 
        rear = nullptr; 
    } 
    void MakeEmpty();
    void Enqueue(Item item);
    Item& Dequeue();
    bool IsEmpty();
    bool IsFull();
    Item& Front(); 
    ~QueueLi(){
        MakeEmpty(); 
    }
};