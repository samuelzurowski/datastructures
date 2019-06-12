// Inspired by TheChernoProject

#include <iostream>
#include <string.h>

class String{
  private: 
    char * s;
    unsigned int size; 
    
  public:
    String(const char* str){
      size = strlen(str); 
      s = new char[size + 1];
      memcpy(s, str, size);
      s[size] = 0; 
    }

    // Copy Constructor
    String(const String& other): size(other.size){
      s = new char[size+1]; 
      memcpy(s, other.s, (size_t)size+1); 
    }

    char& operator[](unsigned int index){
      return s[index]; 
    }

    ~String()
    {
      delete[] s; 
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
  stream << string.s; 
  return stream; 
}

int main() {
  String s = "Tester";
  String s2 = s; 

  s[3] = '#';
   
  std::cout << s << std::endl;
  std::cout << s2 << std::endl;

}