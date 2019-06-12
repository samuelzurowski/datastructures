#include <iostream>
using namespace std; 
long foo(long);

long factorial(long n){
    if(n == 1) return 1;         // Base case
    cout << n << endl;
    return n * factorial(n - 1); // General case
}

// 4 --> 4 * 3 * 2 * 1
// 3 --> 3 * 2 * 1
// 2 --> 2 * 1
// 1 --> 1 
int main(int argc, char** argv){
    long n = factorial(4);
    cout << "Fact4:" << n << endl;
}