#include <iostream>
#include <vector>
#define MAX_LEN 1000000

using namespace std; 

// Heap structure:
// 0th index is reserved for easier computation. Start at 1
// Array [R][1][3][2][8][5][4][7]
// Index  0  1  2  3  4  5  6  7 
// Children of element i are i*2 and i*2 + 1
/*
             [1]
         [3]     [2]
       [8] [5] [4] [7]   
*/

class PriorityQueue{
private:
    int q[MAX_LEN + 1];
    int nElements; 

    int Parent(int idx){
        if(idx == 1) return -1;
        return idx / 2;     // Works for left and right child due to integer division
    }

    int LeftChild(int idx){
        return idx * 2;
    }

    int RightChild(int idx){
        return idx * 2 + 1;
    }
    
    void Swap(int& a, int& b){
        int temp = a;
        a = b; 
        b = temp;
    }

    void BubbleUp(int idx){
        if(Parent(idx) == -1) return; 

        if(q[Parent(idx)] > q[idx]){
            Swap(q[Parent(idx)], q[idx]);
            BubbleUp(Parent(idx));
        }
    }

    void Insert(int item){
        if(nElements >= MAX_LEN)
            throw "PQ Full";
        
        nElements += 1;
        q[nElements] = item; 

        BubbleUp(nElements);
    }

    void BubbleDown(int idx){
        int leftIdx = LeftChild(idx); 
        int rightIdx = RightChild(idx);

        if (leftIdx > nElements) return;

        int minChild; 
        if(leftIdx == nElements){
            minChild = leftIdx;
        }else{
            minChild = q[leftIdx] < q[rightIdx] ? leftIdx : rightIdx;
        }

        if(q[idx] > q[minChild]){
            Swap(q[idx], q[minChild]); 
            BubbleDown(minChild);
        }
    }

    int ExtractMin(){
        if(nElements == 0) 
            throw "PQ Empty";

        int min = q[1];
        q[1] = q[nElements];
        nElements--;
        BubbleDown(1);
        return min;
    }
  
public:
    PriorityQueue():
        nElements{0}
    {}     

    void Enqueue(int key){
        Insert(key);
    }

    int Dequeue(){
        return ExtractMin();
    }

    void MakeEmpty(){
        nElements = 0; 
    }

    int Length(){
        return nElements; 
    }

    bool IsEmpty(){
        return nElements == 0;
    }

    void Heapify(int in[], int length){
        for(int i = 0; i < length; ++i){
            Enqueue(in[i]);
        }
    }

    ~PriorityQueue(){
        MakeEmpty();
    }

    friend ostream& operator<<(ostream& out, PriorityQueue& q);

};

ostream& operator<<(ostream& out, PriorityQueue& q){
    if (q.nElements == 0)
        return out << "[]" << endl;

    for(int i = 1; i <= q.nElements; ++i){
        out << "[" << q.q[i] << "]";
    }
    out << endl;
    return out; 

}

