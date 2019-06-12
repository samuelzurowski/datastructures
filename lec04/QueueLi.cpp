#include "QueueLi.hpp"

void QueueLi::MakeEmpty(){
    Node* temp;
    while(front != nullptr){
        temp = front; 
        front = front->next; 
        delete temp;
    }
    rear = nullptr; //Dont point at memory that's given back!
}
bool QueueLi::IsEmpty(){
    return (front == nullptr);
}
bool QueueLi::IsFull(){
    try{
        Node* temp = new Node; 
        delete temp;
    }catch(std::bad_alloc){
        return true; 
    }
    return false; 
}
// TODO: Resolve reference vs value
void QueueLi::Enqueue(Item item){
    if(IsFull())
        throw QueueFullException();
    
    Node* newNode = new Node(); 
    newNode->data = item; 
    newNode->next = nullptr;
    if(rear == nullptr){
        front = newNode; 
    }else{
        rear->next = newNode; 
    }
    rear = newNode; 
}

Item& QueueLi::Front(){
    if(IsEmpty())
        throw QueueEmptyException();

    return front->data; 
}

Item& QueueLi::Dequeue(){
    if(IsEmpty())
        throw QueueEmptyException();

    Node* temp; 
    temp = front; 
    Item& item = front->data;
    front = front->next; 
    if(front == nullptr)
        rear = nullptr; 
    delete temp; 

    return item;
    
}
