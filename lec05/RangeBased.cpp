#include <iostream>
#include "ArrayListIterator.hpp"
#define MAX_LENGTH 100
using namespace std; 

template <typename T>
class UnorderedList{
    public:
        void virtual MakeEmpty()=0;
        void virtual PutItem(T t)=0;
        void virtual GetItem(T& t, bool& found)=0;
        void virtual DeleteItem(T t)=0;
        void virtual ResetList()=0;
        T virtual GetNextItem()=0; 
        int virtual GetLength()=0;

};

template <typename T>
ostream& operator<<(ostream& out, UnorderedList<T>& list){
    list.ResetList(); 
    for(int i = 0; i < list.GetLength(); ++i){
        out << "[" << list.GetNextItem() << "]"; 
    }
    return out; 
}

template <typename T>
class ArrayList: public UnorderedList<T>{
    public:
        ArrayList(): currentPos{0}, length{0}{
            data = new T[MAX_LENGTH];
        }
        ArrayList(int maxLength): currentPos{0}, length{0}{
            data = new T[maxLength];
        }

        
        ArrayList(const ArrayList& a);                  //Copy constructor
        ArrayList& operator=(const ArrayList& other);   //Copy assignment
        
        void MakeEmpty();
        void PutItem(T t);
        void GetItem(T& t, bool& found);
        void DeleteItem(T t);
        void ResetList();
        T GetNextItem();
        int GetLength();
        ArrayListIterator<T> begin();
        ArrayListIterator<T> end();
        ~ArrayList();
                
    private:
        int currentPos;
        int length;
        T* data;
};

template <typename T>
ArrayListIterator<T> ArrayList<T>::begin(){
    return ArrayListIterator<T>(this->data);  
}

template <typename T>
ArrayListIterator<T> ArrayList<T>::end(){
    return ArrayListIterator<T>(this->data + this->length);  
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& a):
    data{new T[a.length]},
    length{a.length}
{
    for(int i = 0; i < length; ++i){
        data[i] = a.data[i];
    }
}

template <typename T> 
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other){

}

template <typename T>
void ArrayList<T>::MakeEmpty(){
    length = 0;
}
template <typename T>
void ArrayList<T>::PutItem(T t){
    data[length++] = t; 
}
template <typename T>
void ArrayList<T>::GetItem(T& t, bool& found){
    found = false; 
    for(int i = 0; i < length; ++i){
        if (data[i] == t) {
            t = data[i];
            found = true; 
            return; 
        }
    }
}
template <typename T>
void ArrayList<T>::DeleteItem(T t){
    for(int i = 0; i < length; ++i){
        if (data[i] == t)   
            data[i] = data[--length];
    }
}
template <typename T>
void ArrayList<T>::ResetList(){
    currentPos = 0; 
}
template <typename T>
T ArrayList<T>::GetNextItem(){
    if(currentPos < length)
        return data[currentPos++];
    
    throw "Out of Range";
}
template <typename T>
int ArrayList<T>::GetLength(){
    return length; 
}

template <typename T>
ArrayList<T>::~ArrayList(){
    delete[] data; 
}

int main(void){
    ArrayList<int> ar; 
    ar.PutItem(1);
    ar.PutItem(2);
    ar.PutItem(3);
    ar.PutItem(4);
    ar.PutItem(5);
    ar.PutItem(6);

    for(auto i : ar){
        cout << "[" << i << "]"; 
    }
    cout << endl;

}