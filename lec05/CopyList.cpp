#include <iostream>
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
        ~ArrayList();
                
    private:
        int currentPos;
        int length;
        T* data;
};


// Copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other):
    data{new T[other.length]},
    length{other.length}{
    for(int i = 0; i < length; ++i){
        data[i] = other.data[i];
    }
}

// Copy assignment
template <typename T> 
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other){
    T* p = new T[other.length];
    for(int i = 0; i < other.length; ++i)
        p[i] = other.data[i];
    delete[] data;
    data = p; 
    length = other.length; 
    return *this; 
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
    auto list1 = ArrayList<int>(1000); 
    list1.PutItem(12);
    list1.PutItem(24);
    list1.PutItem(48);
    list1.PutItem(96);

    ArrayList<int> list2;
    list2 = list1;   //will invoke copy assignment
    std::cout << "Before:" << endl;
    std::cout << "List 1: " << list1 << endl; 
    std::cout << "List 2: " << list2 << endl; 
    
    list2.DeleteItem(24);

    std::cout << "\nAfter:" << endl;
    std::cout << "List 1: " << list1 << endl; 
    std::cout << "List 2: " << list2 << endl; 

    ArrayList<int> list3 = list2; 

    std::cout << "List 3 (Copy constructor)" << endl; 
    std::cout << list3 << endl;

}