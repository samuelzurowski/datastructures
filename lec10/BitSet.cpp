#include <iostream>
#include <string>
using namespace std; 

class Set{
private:
    unsigned chars;

public: 
    Set(){
        chars = 0;      // Initialize all bits to 0 
    }

    Set(unsigned chars):chars{chars}{}

    void Add(char item){
        unsigned mask = 1; 
        chars |= mask << (item - 'a');  
    }

    void Remove(char item){
        unsigned mask = 1; 
        chars &= ~(mask << (item - 'a')); 
    }

    Set Union(Set other){
        return Set(this->chars | other.chars);  
    }

    Set Intersection(Set other){
        return Set(this->chars & other.chars); 
    }

    Set Difference(Set other){
        return Set(this->chars & ~(other.chars)); 
    }

    friend ostream& operator<<(ostream& out, const Set& s);
};

ostream& operator<<(ostream& out, const Set& s){
    out << "{";
    unsigned mask = 1;
    int i = 0; 
    bool first = true; 
    while(i < 26){
        if(s.chars & mask << i){
            if(first){
                first = false; 
            }else{
                out << ", "; 
            }
            out << char('a' + i); 
        } 
        i += 1; 
    }
    out << "}" << endl;
    return out; 
}

int main(void){
    Set a;
    Set b;
    
    a.Add('a');
    a.Add('w');
    a.Add('s');

    b.Add('b');
    b.Add('w');
    b.Add('u');

    cout << a; 
    cout << b; 

    cout << "Union: " << a.Union(b);
    cout << "Intersection: " << a.Intersection(b);
    cout << "Difference: " << a.Difference(b);

}