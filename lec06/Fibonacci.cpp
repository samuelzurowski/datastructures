#include <iostream>
#include <vector>

int Fibonacci(int n){
    if(n == 0) return 0; 
    if(n == 1) return 1; 
    return Fibonacci(n - 1) + Fibonacci(n - 2); 
}

// Dynamic Implementation

int FibonacciDyn(int n, int memo[]){
    if (n == 0 || n == 1) return n; 

    if(memo[n] == 0)
        memo[n] = FibonacciDyn(n - 1, memo) + FibonacciDyn(n - 2, memo); 

    return memo[n];  
}

int FibonacciDyn(int n){
    int* memo = new int[n+1]{0};  
    return FibonacciDyn(n, memo); 
}

int main(void){
    int i = 0; 
    while(i < 45)
        std::cout << Fibonacci(i++) << std::endl;
}
