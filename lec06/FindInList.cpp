#include <iostream>
using namespace std; 

struct List{
    int ar[10]; 
    int length; 
};

// Iterative Implementation
bool InList(int value, const List& list){
    for(int i = 0; i < list.length; ++i){
        if(list.ar[i] == value)
            return true; 
    }
    return false; 
}

// Recursive Implementation
bool InList(int value, int start, const List& list){
    if(start == list.length)
        return false; 
    
    return (list.ar[start] == value) || InList(value, start+1, list); 
}

int main(void){
    List list;
    list.length = 10; 
    for(int i = 0; i < 10; ++i){
        list.ar[i] = i;
    }

    for(int i = -1; i < 12; ++i){
        cout << (InList(i, 0, list) ? "In list" : "Not in list") << endl; 
    }
}