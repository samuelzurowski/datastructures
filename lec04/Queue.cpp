#include "Queue.hpp"

std::ostream& operator<<(std::ostream& out, Queue& s){
    out << "Queue: ["; 
    if (s.IsEmpty()) 
        out << "(Empty)"; 
    else
    {
        out << "(Not-Empty)"; 
    }
    out << "]";
    return out; 
}