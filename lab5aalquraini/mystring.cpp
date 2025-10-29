#include <cstring>
#include <iostream>
#include <iomanip>
#include <cctype>
#include "mystring.h"


namespace coen79_lab5{

    string::string(const char str[]) {  // default argument is the empty string.
        current_length = std::strlen(str); // length without null terminator
        allocated = current_length + 1; // +1 for null terminator
        characters = new char[allocated]; // allocate memory
        std::strncpy(characters, str, allocated); // copy string including null terminator
    }

    string::string(char c) { // construct string from single character
        current_length = 1; // only one character
        allocated = 2; // one for character and one for null terminator
        characters = new char[allocated];
        characters[0] = c; 
        characters[1] = '\0'; // null terminator
    }

    string::string(const string& source){ //    Copy Constructor.
        current_length = source.current_length; // length without null terminator
        allocated = source.allocated;
        characters = new char[allocated]; // allocate memory
        std::strncpy(characters, source.characters, allocated); // copy string including null terminator
    }

    string::~string(){   // Destructor
        if((characters == nullptr)) { return; } // nothing to delete
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
            reserve(allocated * 2);
        }

        characters[current_length++] = addend;
        characters[current_length] = '\0';
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
        delete [] characters;
        characters = new char[source.allocated];
        std::strncpy(characters, source.characters, source.allocated);
        current_length = source.current_length;
        allocated = source.allocated;
        return *this;
    }

    void string::insert(const string& source, unsigned int position){
        // position must be valid (allowed to insert at end)
        if(position > current_length){
            throw std::out_of_range("Index out of range");
        }

        // Ensure there is enough space for the new characters + null terminator
        size_t needed = current_length + source.current_length + 1;
        while(needed > allocated){
            reserve(allocated * 2);
        }

        // iterate backwards to avoid overwriting
        for(int i = static_cast<int>(current_length); i >= static_cast<int>(position); --i){
            characters[i + static_cast<int>(source.current_length)] = characters[i];
        }

        // Copy the source into the gap
        for(size_t i = 0; i < source.current_length; ++i){
            characters[position + i] = source.characters[i];
        }

        // Update length and ensure null termination
        current_length = current_length + source.current_length;
        characters[current_length] = '\0';
    }

    void string::dlt(unsigned int position, unsigned int num){
        if(position + num > current_length){
            throw std::out_of_range("Index out of range");
        }
        for(auto i = position; i <= current_length; i++){
            characters[i] = characters[i+num];
        }
        current_length -= num;
        characters[current_length] = '\0';
    }

    void string::replace(char c, unsigned int position){
        if(position >= current_length){
            throw std::out_of_range("Index out of range");
        }
        characters[position] = c;
    }

    void string::replace(const string& source, unsigned int position){
        if(position >= current_length){
            throw std::out_of_range("Index out of range");
        }
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
        string ret_string(s1);
        ret_string += s2;
        return ret_string;
    }

    string operator +(const string& s1, const char addend[]){
        string ret_string(s1);
        ret_string += addend;
        return ret_string;
    }

    std::istream& operator >> (std::istream& ins, string& target){
        // skip initial whitespace (consume)
        int ch;
        while (ins && (ch = ins.peek()) != EOF && std::isspace(static_cast<unsigned char>(ch))){
            ins.get();
        }

        if (!ins || ins.peek() == EOF) return ins; // nothing to read

        // read a word into a fixed buffer (leave terminating whitespace unread)
        char buffer[1000];
        if (!(ins >> std::setw(sizeof(buffer)) >> buffer)) return ins; // extraction failed

        target = string(buffer);
        return ins;
    }
}