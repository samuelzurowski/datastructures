#include <iostream>
using namespace std;

#define LENGTH 10

int BinarySearch(int value, int ar[], int left, int right){
    if(right < left)
        return -1; 

    int mid = (left + right) / 2;
    if(value == ar[mid])
        return mid;
    else if(value < ar[mid])
        return BinarySearch(value, ar, left, mid - 1);
    else
        return BinarySearch(value, ar, mid + 1, right); 
}

int _BinarySearch(int value, int ar[]){
    return BinarySearch(value, ar, 0, LENGTH - 1);
}

int main(void){
    int ar[LENGTH] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << _BinarySearch(20,  ar) << " Should be  1" << endl; 
    cout << _BinarySearch(25,  ar) << " Should be -1" << endl; 
    cout << _BinarySearch(100, ar) << " Should be  9" << endl; 
    cout << _BinarySearch(10,  ar) << " Should be  0" << endl; 

}

