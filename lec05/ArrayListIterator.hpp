
template<typename T>
class ArrayListIterator{
public:
    ArrayListIterator(T* start); 
    T& operator*();
    ArrayListIterator<T>& operator++();
    bool operator!=(const ArrayListIterator<T>& it) const; 
private: 
    T* item; 
    T* end; 
};

template<typename T>
ArrayListIterator<T>::ArrayListIterator(T* start){
    this->item = start;
}

template<typename T>
T& ArrayListIterator<T>::operator*(){
    return *item; 
}

template<typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator++(){
    item++; //This is pointer arithmetic, NOT value  
    return *this; 
}

template<typename T>
bool ArrayListIterator<T>::operator!=(const ArrayListIterator<T>& it) const{
    return this->item != it.item; 
} 
