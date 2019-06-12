#include "QueueAr.hpp"

void QueueAr::MakeEmpty()
{
    front = rear = maxLength-1;
}
void QueueAr::Enqueue(Item item)
{
    if(IsFull())
        throw QueueFullException();
    
    rear = (rear + 1) % maxLength; 
    items[rear] = item; 

}

Item& QueueAr::Front(){
    if(IsEmpty())
        throw QueueEmptyException();

    return items[(front + 1) % maxLength];
}

Item& QueueAr::Dequeue(){
    if(IsEmpty())
        throw QueueEmptyException(); 
    
    front = (front + 1) % maxLength; 
    return items[front];
}
bool QueueAr::IsEmpty(){
    return (front == rear); 
}

bool QueueAr::IsFull(){
    return ((rear + 1) % maxLength == front); 
}
