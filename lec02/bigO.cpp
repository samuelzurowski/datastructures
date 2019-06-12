#include <iostream>
#include <vector>
using namespace std;

void f1(void){ // o(1)
    vector<int> v {1, 2, 3, 4, 5, 6}; 
    cout << v[3] << endl;
}

int f2(int n){ // o(n)
    int sum = 0; 
    for (int i = 0; i < n; ++i){
        sum += i; 
    }
    return sum; 
}

void f3(int n){ // o(1)
    int res = 0; 
    for (int i = 0; i < 100; ++i){
        res += n; 
    }    
}

void f4(int n){ // o(n^2)
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++i){
            cout << i * j; 
        }
    }
}

void f5(int n){ // nlog(n)
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i; ++j)
        {
            cout << ":)"; 
        }
    }
}

int f6(int n){ // o(n^2)
    int res = f2(n);
    f3(n);
    f4(n);
    return res; 
}

void f7(int n){  // o(n^2)
    for (int i = 0; i < n; ++i){
        f2(n); 
    }
}

void f8(int n){ // o(n)
    for (int i = 0; i < n; ++i){
        cout << i; 
    }
    // o(n)
    for (int i = 0; i < n/2; ++i){
        cout << i * i; 
    }
}

void f9(int n, int k){ // o(n^2)
    for (int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            cout << n << ", " << k;
        }
    }
}

void f10(int n){ // o(logn)
    int k = 0; 
    while (n > 0){
        k += 1; 
        //cout << n << "->"; 
        n /= 2; 
    }
    cout << k << endl; 
}
//o(logn)
int main(void){
    for(int i = 0; i < 33; ++i){
        f10(i); 
    }
}