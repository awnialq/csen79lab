#include <cstring>
#include <iostream>
#include "mystring.h"


namespace coen79_lab5{

    string::string(const char str[] = "") {
        current_length = std::strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        std::strncpy(characters, str, allocated);
    }

    string::string(char c) {
        current_length = 1;
        allocated = 2; // one for character and one for null terminator
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }

    string::string(const string& source){
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[allocated];
        std::strncpy(characters, source.characters, allocated);
    }

    string::~string(){
        if((characters == nullptr)) { return; }
        delete [] characters;
    }

    void string::operator +=(const string& addend){
        while(addend.current_length + current_length + 1 > allocated){
            reserve(allocated * 2);
        }

        std::strncat(characters, addend.characters, addend.current_length);
        current_length += addend.current_length;
    }

    void string::operator +=(const char addend[]){
        while(std::strlen(addend) + current_length + 1 > allocated){
            reserve(allocated * 2);
        }

        std::strncat(characters, addend, std::strlen(addend));
        current_length += std::strlen(addend);
    }

    void string::operator +=(char addend){
        if(current_length + 1 >= allocated){
            reserve(allocated + 1);
        }

        characters[current_length++] = addend;
        characters[current_length + 1] = '\0';
    }

    void string::reserve(size_t n){
        if(n  <= allocated){ return; }
        char *temp = new char[n];
        std::strncpy(temp, characters, current_length + 1);
        delete [] characters;
        characters = temp;
        allocated = n;
    }

    string& string::operator =(const string& source){
        std::strncpy(characters, source.characters, allocated);
        current_length = source.current_length;
        allocated = source.allocated;
        return *this;
    }

    void string::insert(const string& source, unsigned int position){
        while(source.current_length + position + 1 >= allocated){
            reserve(allocated * 2);
        }

        

        std::strncpy(characters + position, source.characters, source.current_length);
        current_length = position + source.current_length;
        characters[current_length + 1] = '\0';
    }

    void string::dlt(unsigned int position, unsigned int num){
        for(auto i = position; i <= current_length; i++){
            characters[i] = characters[i+num];
        }
        current_length -= num;
        characters[current_length] = '\0';
    }

    void string::replace(char c, unsigned int position){
        characters[position] = c;
    }

    void string::replace(const string& source, unsigned int position){
        if(source.current_length + position > current_length){
            reserve(allocated * 2);
        }
        for(auto i = 0; i < source.current_length; i++){
            characters[position + i] = source.characters[i];
        }
    }

    char string::operator [](size_t position) const{
        if(position >= current_length){
            throw std::out_of_range("Index out of range");
        }
        return characters[position];
    }

    int string::search(char c) const{
        for(auto i = 0; i < current_length; i++){
            if(characters[i] == c){
                return i;
            }
        }
        return -1;
    }

    int string::search(const string& substring) const{
        char *addr = std::strstr(characters, substring.characters);
        if(addr != nullptr){
            return addr - characters;
        }
        return -1;
    }

    unsigned int string::count(char c) const{
        unsigned int cnt = 0;
        for(auto i = 0; i < current_length; i++){
            if(characters[i] == c){
                cnt++;
            }
        }
        return cnt;
    }

    std::ostream& operator <<(std::ostream& outs, const string& source){
        outs << source.characters;
        return outs;
    }

    bool operator ==(const string& s1, const string& s2){
        if(s1.current_length != s2.current_length){
            return false;
        }
        return std::strncmp(s1.characters, s2.characters, s1.current_length) == 0;
        
    }

    bool operator !=(const string& s1, const string& s2){
        return !(s1 == s2);
    }

    bool operator > (const string& s1, const string& s2){
        return std::strncmp(s1.characters, s2.characters, std::min(s1.current_length, s2.current_length)) > 0;
    }

    bool operator < (const string& s1, const string& s2){
        return (s2 > s1);
    }

    bool operator >=(const string& s1, const string& s2){
        if(s1 == s2){ return true; }
        return s1 > s2;
    }

    bool operator <=(const string& s1, const string& s2){
        if(s1 == s2){ return true; }
        return s2 > s1;
    }

    string operator +(const string& s1, const string& s2){
        return string(s1 += s2);
    }

    string operator +(const string& s1, const char addend[]){
        return string(s1 += s2);
    }

    std::istream& operator >> (std::istream& ins, string& target){
        while(ins && std::isspace(ins.peek())){
            ins.ignore();
        }
        
    }
}