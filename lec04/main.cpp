#include "StackAr.hpp"
#include "StackLi.hpp"
#include "QueueAr.hpp"
#include "QueueLi.hpp"
#include "Item.hpp"
#include <iostream>

void TestQueue(Queue* q){
    cout << endl << endl <<"Testing Queue" << endl << endl;

    cout << *q << endl;
    cout << "Queuing 1-4" << endl;
    q->Enqueue(Item(1, ""));
    q->Enqueue(Item(2, ""));
    q->Enqueue(Item(3, ""));
    q->Enqueue(Item(4, ""));
    cout << *q <<endl; 

    q->Dequeue();
    cout << *q <<endl; 

    cout << q->Front() << endl;

    for(int i = 0; i < 3; ++i){
        try{
            cout << "Dequeuing: " << q-> Dequeue() << endl; 
        }catch(QueueEmptyException e){
            cerr << "Queue is empty" << endl;; 
        }
    }

    for(int i = 0; i < 5; ++i){
        try{
            Item item(i, "");
            cout << "Queueing: " << item << endl;
            q->Enqueue(item); 
        }catch(QueueFullException e){
            cerr << "Queue is full" << endl;
        }
    }
    cout << *q <<endl; 
}

void TestStack(Stack* s){
    cout << endl << endl <<"Testing Stack" << endl << endl;

    cout << *s <<endl; 
    cout << "Pushing 1-4" << endl; 
    s->Push(Item(1, ""));
    s->Push(Item(2, ""));
    s->Push(Item(3, ""));
    s->Push(Item(4, ""));
    cout << *s <<endl; 

    cout << s->Top() << endl;

    for(int i = 0; i < 3; ++i){
        try{
            cout << "Popping: " << s->Top() << endl;
            s->Pop() ;
        }catch(StackEmptyException e){
            cerr << e.message << endl;; 
        }
    }

    for(int i = 0; i < 5; ++i){
        try{
            Item item(i, "");
            cout << "Pushing: " << item << endl;
            s->Push(item); 
        }catch(StackFullException e){
            cerr << e.message << endl;
        }
    }
    cout << *s <<endl; 
}

int main(void){
    Stack* s = new StackAr(); 
    TestStack(s); 
    delete s; 

    s = new StackLi(); 
    TestStack(s); 
    delete s; 

    Queue* q = new QueueAr(); 
    TestQueue(q); 
    delete q; 

    q = new QueueLi();
    TestQueue(q); 
    delete q;     
}