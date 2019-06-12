#pragma once

template<typename T>
class Pair{
private:
    T first; 
    T second;

public:
    Pair(T first, T second);
    T GetFirst(); 
    T GetSecond();
    void SetFirst(T first); 
    void SetSecond(T second);
};

template <typename T>
Pair<T>::Pair(T first, T second):
    first{first}, 
    second{second}
{}

template <typename T>
T Pair<T>::GetFirst(){
    return first; 
}

template <typename T>
T Pair<T>::GetSecond(){
    return second; 
}

template <typename T>
void Pair<T>::SetFirst(T first){
    this->first = first; 
}

template <typename T>
void Pair<T>::SetSecond(T second){
    this->second = second; 
}