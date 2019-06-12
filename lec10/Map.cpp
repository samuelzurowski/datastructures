#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std; 

struct Student{
    string name;
    int graduationYear; 

    Student(string name, int graduationYear):
        name{name},
        graduationYear{graduationYear}{}
};

int main(void){
    // unordered_map<char, Student*> map;       // Hash table implementation
    map<char, Student*> map;                    // Red-black tree implementation
    Student* s1 = new Student("Joe", 2020);
    Student* s2 = new Student("Jane", 2021);
    Student* s3 = new Student("Jim", 2022);

    map['a'] = s1; 
    map['b'] = s2; 
    map['c'] = s3; 

    cout << map['b']->name << endl;
}
