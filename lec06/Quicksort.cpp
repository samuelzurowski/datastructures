#include <iostream>
#define LENGTH 9
void swap(int* i, int* j){
    int temp = *i; 
    *i = *j; 
    *j = temp; 
}

int Partition(int* ar, int first, int last){
    int pivot = ar[last]; 
    int i = first-1;    // Will represent last element smaller than pivot
    // when the array position is smaller than the last position of the array
    for(int j = first; j < last; ++j){
        // if this element is smaller than the last element
        int val = ar[j];
        if(val <= pivot){

            // increment the i
            i += 1; 

            //swaps element at the sort position with the array position
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[last], &ar[i+1]);
    return i + 1; 
}

void Quicksort(int* ar, int first, int last){
    if(first < last){
        int div = Partition(ar, first, last); 
        Quicksort(ar, first, div - 1); 
        Quicksort(ar, div+1, last); 
    }
}

int main(void){
    int ar[LENGTH] = {3, 7, 5, 9, 1, 2, 4, 6, 8};
    for(auto v: ar){
        std::cout << "[" << v << "]"; 
    }
    std::cout << std::endl;

    Quicksort(ar, 0, LENGTH-1);
    
    for(auto v: ar){
        std::cout << "[" << v << "]"; 
    }
    std::cout << std::endl;

}