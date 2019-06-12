#include <iostream>
#include <vector>
#include "PriorityQueue.hpp"
#include <chrono>
#include <string>
#include <fstream>

#define OUTPUT_PATH "./results.csv"

using namespace std; 
using namespace std::chrono;

class Sorter{
private: 
    string name; 
protected:
    void swap(int* i, int* j){
        int temp = *i; 
        *i = *j; 
        *j = temp; 
    }
public:
    Sorter(string name):name{name}{}
    virtual void Sort(int ar[], int length)=0;
    string GetName(){return name;}
    virtual ~Sorter(){}
};

class HeapSorter: public Sorter{
private:
    void HeapSort(int ar[], int length){
        PriorityQueue q; 
        q.Heapify(ar, length);
        for(int i = 0; i < length; ++i){
            ar[i] = q.Dequeue(); 
        }
    }

public:
    HeapSorter():
        Sorter("Heap Sort")
    {}
    void Sort(int ar[], int length){
        HeapSort(ar, length);
    }
};

class SelectionSorter: public Sorter{
private:
    void SelectionSort(int ar[], int length)
    {
        int jMin, temp;
        
        for(int i = 0; i < length - 1; ++i){
            jMin = i;
            for(int j = i+1; j < length; ++j){
                if(ar[j] < ar[jMin])
                    jMin = j;
            }
            if(jMin != i){
                swap(&ar[i], &ar[jMin]);
            }
        }
    }

public:
    SelectionSorter():
        Sorter("Selection Sort")
    {}
    void Sort(int ar[], int length){
        SelectionSort(ar, length);
    }
};

class InsertionSorter: public Sorter{
private:
    void InsertionSort(int ar[], int length){
        for(int i = 1; i < length; ++i){
            for(int j = i; j > 0 && ar[j-1] > ar[j]; --j){
                swap(&ar[j], &ar[j-1]);
            }
        }
    }

    void InsertionSort2(int ar[], int length){
        int temp; 
        for(int i = 1; i < length; ++i){
            for(int j = i; j > 0 && ar[j-1] > ar[j]; --j){
                temp = ar[j]; 
                ar[j] = ar[j-1];
                ar[j-1] = temp;
            }
        }
    }

    void InsertionSort3(int ar[], int length){
        int temp; 
        for(int i = 1; i < length; ++i){
            int j = i; 
            temp = ar[i];
            for(;j > 0 && ar[j-1] > temp; --j){
                ar[j] = ar[j-1];
            }
            ar[j] = temp;
            
        }
    }

public:
    InsertionSorter():
        Sorter("Insertion Sort")
    {}
    void Sort(int ar[], int length){
        InsertionSort3(ar, length);
    }
};

class BubbleSorter: public Sorter{
private:
    void BubbleSort(int ar[], int length){
        bool sorted = false; 
        while(!sorted){
            sorted = true; 
            for(int i = 0; i < length - 1; ++i){
                if(ar[i] > ar[i + 1]){
                    swap(&ar[i], &ar[i+1]);
                    sorted = false; 
                }
            }
        }
    }

    void BubbleSort2(int ar[], int length){
        bool sorted = false; 
        int largestElem = length - 1;
        while(!sorted){
            sorted = true; 
            for(int i = 0; i < largestElem; ++i){
                if(ar[i] > ar[i + 1]){
                    swap(&ar[i], &ar[i+1]);
                    sorted = false; 
                }
            }
            largestElem--;
        }
    }
public: 
    BubbleSorter():
        Sorter("Bubble Sort")
    {}
    void Sort(int ar[], int length){
        BubbleSort2(ar, length);
    }    
};

class QuickSorter: public Sorter{
private:
    int Partition(int ar[], int first, int last){
        int pivot = ar[last]; 
        int i = first-1;    // Will represent last element smaller than pivot
        for(int j = first; j < last; ++j){
            if(ar[j] <= pivot){
                i += 1; 
                swap(&ar[i], &ar[j]);
            }
        }
        swap(&ar[last], &ar[i+1]);
        return i + 1; 
    }

    void QuickSort(int ar[], int first, int last){
        if(first < last){
            int div = Partition(ar, first, last); 
            QuickSort(ar, first, div - 1); 
            QuickSort(ar, div+1, last); 
        }
    }

    void QuickSort(int ar[], int length){
        QuickSort(ar, 0, length-1);
    }
public:
    QuickSorter():
        Sorter("Quick Sort")
    {}
    void Sort(int ar[], int length){
        QuickSort(ar, length);
    }
};

class MergeSorter: public Sorter{
private:
    void Merge(int ar[], int first, int mid, int last){
        int leftSize = mid - first + 1;
        int rightSize = last - mid; 
        int * tempLeft = new int[leftSize];
        int * tempRight = new int[rightSize];
        int i, j, k; 

        for(i = 0; i < leftSize; ++i){
            tempLeft[i] = ar[first + i];
        } 

        for(j = 0; j < rightSize; ++j){
            tempRight[j] = ar[mid + 1 + j]; 
        }

        i = 0; 
        j = 0; 
        k = first; 

        while(i < leftSize && j < rightSize){
            if(tempLeft[i] <= tempRight[j]){
                ar[k] = tempLeft[i]; 
                i++; 
            }else{
                ar[k] = tempRight[j]; 
                j++; 
            }
            k++;
        }

        while(i < leftSize){
            ar[k] = tempLeft[i]; 
            i++; 
            k++; 
        }

        while(j < rightSize){
            ar[k] = tempRight[j];
            j++;
            k++;
        }

        delete [] tempLeft; 
        delete [] tempRight; 
    }
    void MergeSort(int ar[], int first, int last){
        if(first < last){
            int mid = (first + last) / 2; 
            MergeSort(ar, first, mid);
            MergeSort(ar, mid+1, last);
            Merge(ar, first, mid, last); 
        }
    }


public:    
    MergeSorter(): 
        Sorter("Merge Sort")
    {}

    void Sort(int ar[], int length){
        MergeSort(ar, 0, length-1); 
    }

};

class CountingSorter: public Sorter{
private:
    void CountingSort(int ar[], int length)
    {
        int maxValue = ar[0]; 
        for(int i = 0; i < length; ++i){
            if(ar[i] > maxValue)
                maxValue = ar[i];
        }
        int *counts = new int[maxValue + 1]; 
        int *output = new int[length]; 

        for(int i = 0; i <= maxValue; ++i){
            counts[i] = 0; 
        }

        for(int i = 0; i < length; ++i){
            counts[ar[i]] += 1;
        }

        for(int i = 1; i <= maxValue; ++i){
            counts[i] = counts[i] + counts[i-1];
        } 

        for(int i = length - 1; i >= 0; --i){
            output[counts[ar[i]] - 1] = ar[i];
            counts[ar[i]]--;
        }

        for(int i = 0; i < length; ++i){
            ar[i] = output[i];
        }

        delete [] counts; 
        delete [] output; 
    }

public:
    CountingSorter():
        Sorter("Counting Sort")
    {}
    void Sort(int ar[], int length){
        CountingSort(ar, length);
    }
};

void RandomArray(int ar[], int length, int min, int max){
    srand(time(NULL));
    for(int i = 0; i < length; ++i){
        ar[i] = rand()%(max-min + 1) + min;
    }
}

bool AssertSorted(int ar[], int length){
    for(int i = 1; i < length; ++i){
        if(ar[i-1] > ar[i])
            return false;
    }
    return true; 
}

int TimeToSort(Sorter* s, int ar[], int length){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    s->Sort(ar, length);

    if(!AssertSorted(ar, length))
        cout << "NOT SORTED" << endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<microseconds>( t2 - t1 ).count();
}


int main(void){
    /*
    Sorter* s = new CountingSorter();
    int ar[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    s->Sort(ar, 10);
    for(int i = 0; i < 10; ++i){
        cout << ar[i]  << ", ";
    }
    */
    
    auto lengths = vector<int>();
    for(int i = 1; i <= 1000000; i *= 10){
        lengths.push_back(i);
    }

    auto sorters = vector<Sorter*>(); 
    sorters.push_back(new QuickSorter());
    sorters.push_back(new BubbleSorter());
    // sorters.push_back(new CountingSorter());

    auto headers = vector<string>(); 
    headers.push_back("Sort Algo");
    for(auto length : lengths){
        headers.push_back(to_string(length));
    }

    ofstream outFile;
    outFile.open(OUTPUT_PATH);
    for(auto h : headers)
        outFile << h << ", ";
    outFile << endl;


    for(int i = 0; i < sorters.size(); ++i){
        outFile << sorters[i]->GetName() << ", ";
        for(auto length: lengths){
            int* vals = new int[length]; 
            RandomArray(vals, length, 0, 1000000);
            int duration = TimeToSort(sorters[i], vals, length); 
            outFile << duration << ",";
            cout << "Time to sort " << length << " nums with " << sorters[i]->GetName() << ": " << duration << " microseconds" << endl;
        }
        outFile << endl;
        delete sorters[i];
    }


    outFile.close();
    cout << endl;

    
    
}