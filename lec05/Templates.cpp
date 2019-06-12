#include <iostream>
#include <string>
#include "Pair.hpp"
#include "Stack.hpp"

// Function template
template <typename T>
T maximum(T a, T b){
    return a > b ? a : b; 
}

int main(void){
    using namespace std; 
    cout << maximum<double>(1.0, 5.0) << endl; 
    cout << maximum<char>('w', 'a') << endl;
    cout << maximum<string>("apple", "walnut") << endl;


    // A Pair class 
    Pair<string> pair("C++", "Python"); 
    cout << pair.GetFirst() << endl;
    cout << pair.GetSecond() << endl;
    pair.SetSecond("C#"); 
    cout << pair.GetSecond() << endl;

    Stack<int> s1; 
    s1.Push(1);
    s1.Push(2);
    s1.Pop();
    cout << s1.Top() << endl;

    Stack<char> s2; 
    s2.Push('w');
    s2.Push('x');
    s2.Pop();
    cout << s2.Top() << endl;
}

