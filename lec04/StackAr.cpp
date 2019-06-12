#include "StackAr.hpp"

void StackAr::Push(Item item){
    if(IsFull())
        throw StackFullException();
    data[++top] = item; 
}

Item& StackAr::Top(){
    if(IsEmpty())
        throw StackEmptyException();
    return data[top];
}

void StackAr::Pop(){
    if(IsEmpty())
        throw StackEmptyException();
    top--; 
}

bool StackAr::IsFull() const{
    return(top == maxLength - 1); 
}

bool StackAr::IsEmpty() const{ 
    return(top == -1); 
}
