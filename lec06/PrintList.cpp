#include <iostream>

template <typename T>
struct Node{
    Node(T data): data{data}, next{nullptr}{}

    T data; 
    Node* next; 
};

template <typename T>
void PrintList(Node<T>* list){
    if(list == nullptr) return; 

    std::cout << "[" << list->data << "]"; 
    PrintList(list->next); 
}

int main(void){
    Node<int>* list = new Node<int>(0) ; 
    Node<int>* current = list; 
    for (int v : {1, 2, 3, 4, 5})
    {
        current->next = new Node<int>(v); 
        current = current->next; 
    }

    PrintList<int>(list); 
    std::cout << std::endl;

    return 0; 
}