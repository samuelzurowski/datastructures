#include "Stack.hpp"

std::ostream& operator<<(std::ostream& out, Stack& s){
    out << "Stack: ["; 
    if (s.IsEmpty()) 
        out << "(Empty)"; 
    else
    {
        out << "(Not-Empty)"; 
    }
    out << "]";
    return out; 
}