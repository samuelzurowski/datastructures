#include <iostream>
#include <string>
using namespace std; 

class Set{
private:
    bool chars[26];

public:
    Set(){
        for(int i = 0; i < 26; ++i){
            chars[i] = false; 
        }
    }

    int charToIndex(char item) const{
        return item - 'a'; 
    }

    char indexToChar(int index) const{
        return index + 'a'; 
    }

    void Add(char item){
        chars[charToIndex(item)] = true; 
    }

    void Remove(char item){
        chars[charToIndex(item)] = false; 
    }

    int Cardinality(){
        int cardinality = 0;
        for(int i = 0; i < 26; ++i){
            if(chars[i] == true)
                cardinality++; 
        }
        return cardinality; 
    }

    Set Union(Set other){
        Set result; 
        for(int i = 0; i < 26; ++i){
            result.chars[i] = chars[i] || other.chars[i];
        }
        return result; 
    }

    Set Intersection(Set other){
        Set result; 
        for(int i = 0; i < 26; ++i){
            result.chars[i] = chars[i] && other.chars[i];
        }
        return result; 
    }

    Set Difference(Set other){
        Set results; 
        for(int i = 0; i < 26; ++i){
            results.chars[i] = chars[i] && !other.chars[i];
        }
        return results; 
    }


    friend ostream& operator<<(ostream& out, const Set& s);
};

ostream& operator<<(ostream& out, const Set& s){
    out << "{";
    bool first = true; 
    for(int i = 0; i < 26; ++i){
        if (s.chars[i]){
            if(first){
                first = false; 
            }else{
                out << ", ";
            }
            out << s.indexToChar(i);
        }
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