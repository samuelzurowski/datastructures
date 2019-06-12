#include <iostream>
#include "StackAr.hpp"

bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol); 
using namespace std; 

typedef char Item;


int main(void){
    StackAr stack;
    bool balanced = true; 
    char openSymbol; 
    char symbol; 
    cout << "Enter symbols: ";
    cin.get(symbol); 
    while(symbol != '\n' && balanced){
        if(IsOpen(symbol)){
            stack.Push(symbol); 
        }else if(IsClosed(symbol)){
            if(stack.IsEmpty()){
                balanced = false; 
            }else{
                openSymbol = stack.Top(); 
                stack.Pop(); 
                balanced = Matches(symbol, openSymbol); 
            }
        }
        cin.get(symbol); 
    }
    if(!stack.IsEmpty())
        balanced = false; 
    if(balanced)
        cout << "Expression is well formed." << endl;
    else
        cout << "Expression is NOT well formed." << endl;
}

bool IsOpen(char symbol){
    return (symbol == '(' || symbol == '{' || symbol == '[');
}
bool IsClosed(char symbol){
    return (symbol == ')' || symbol == '}' || symbol == ']');
}
bool Matches(char symbol, char openSymbol){
    return (
        (openSymbol == '(' && symbol == ')') ||
        (openSymbol == '[' && symbol == ']') ||
        (openSymbol == '{' && symbol == '}')   
    );
}
