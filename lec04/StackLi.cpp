#include "StackLi.hpp"

void StackLi::Push(Item item){
    Node* temp = new Node; 
    temp->data = item; 
    temp->next = top; 
    top = temp; 
}

Item& StackLi::Top(){
    if(IsEmpty())
        throw StackEmptyException(); 
    return top->data; 
}

void StackLi::Pop(){
    if (IsEmpty())
        throw StackEmptyException();
    Node* temp = top;
    top = top->next; 
    delete temp;  
}

bool StackLi::IsFull() const{
    try{
        Node* temp = new Node; 
        delete temp;
    }catch(std::bad_alloc){
        return true; 
    }
    return false; 
}

bool StackLi::IsEmpty() const{
    return(top == nullptr); 
} 

StackLi::~StackLi(){
    Node* temp;
    while(top != nullptr){
        temp = top; 
        top = top->next;
        delete temp;  
    }
}

