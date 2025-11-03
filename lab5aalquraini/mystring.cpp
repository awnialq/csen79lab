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
        while(addend.current_length + current_length + 1 > allocated){  // make sure there is enough space
            reserve(allocated * 2);
        }

        std::strncat(characters, addend.characters, addend.current_length); // concatenate addend
        current_length += addend.current_length;    // update length
    }

    void string::operator +=(const char addend[]){  // concatenate C-string
        while(std::strlen(addend) + current_length + 1 > allocated){ // make sure there is enough space
            reserve(allocated * 2);
        }
        std::strncat(characters, addend, std::strlen(addend)); // concatenate addend
        current_length += std::strlen(addend); // update length
    }

    void string::operator +=(char addend){  // concatenate single character
        if(current_length + 1 >= allocated){ // make sure there is enough space
            reserve(allocated * 2);
        }

        characters[current_length++] = addend; // add character and update length
        characters[current_length] = '\0'; // null terminate
    }

    void string::reserve(size_t n){
        if(n  <= allocated){ return; } // no need to reserve
        char *temp = new char[n]; // allocate new memory
        std::strncpy(temp, characters, current_length + 1); // copy existing characters including null terminator
        delete [] characters; // delete old memory
        characters = temp; // point to new memory
        allocated = n; // update allocated size
    }

    string& string::operator =(const string& source){ // assignment operator
        delete [] characters; // delete old memory
        characters = new char[source.allocated]; // allocate new memory
        std::strncpy(characters, source.characters, source.allocated); // copy characters including null terminator
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
        if(position + num > current_length){ // validate range
            throw std::out_of_range("Index out of range");
        }
        for(auto i = position; i <= current_length; i++){ // shift characters left
            characters[i] = characters[i+num];
        }
        current_length -= num; // update length
        characters[current_length] = '\0'; // null terminate
    }

    void string::replace(char c, unsigned int position){ // replace single character
        if(position >= current_length){ // validate position
            throw std::out_of_range("Index out of range");
        }
        characters[position] = c; // replace character
    }

    void string::replace(const string& source, unsigned int position){
        if(position >= current_length){  // validate position
            throw std::out_of_range("Index out of range");
        }
        if(source.current_length + position > current_length){ // ensure enough space
            reserve(allocated * 2);
        }
        for(auto i = 0; i < source.current_length; i++){ // copy source characters
            characters[position + i] = source.characters[i];
        }
    }

    char string::operator [](size_t position) const{    // access character at position
        if(position >= current_length){
            throw std::out_of_range("Index out of range");
        } 
        return characters[position];
    }

    int string::search(char c) const{   // search for character
        for(auto i = 0; i < current_length; i++){ // linear search
            if(characters[i] == c){
                return i;
            }
        }
        return -1;
    }

    int string::search(const string& substring) const{  // search for substring
        char *addr = std::strstr(characters, substring.characters); // find substring
        if(addr != nullptr){    // found
            return addr - characters; // calculate index
        }
        return -1;
    }

    unsigned int string::count(char c) const{
        unsigned int cnt = 0;   // count occurrences of character
        for(auto i = 0; i < current_length; i++){
            if(characters[i] == c){ // match found
                cnt++;
            }
        }
        return cnt;
    }

    std::ostream& operator <<(std::ostream& outs, const string& source){ // output string
        outs << source.characters; // output characters
        return outs;
    }

    bool operator ==(const string& s1, const string& s2){ // equality operator
        if(s1.current_length != s2.current_length){ // lengths differ
            return false;
        }
        return std::strncmp(s1.characters, s2.characters, s1.current_length) == 0;  // compare characters
        
    }

    bool operator !=(const string& s1, const string& s2){   // inequality operator
        return !(s1 == s2); // negate equality
    }

    bool operator > (const string& s1, const string& s2){
        return std::strncmp(s1.characters, s2.characters, std::min(s1.current_length, s2.current_length)) > 0; // lexicographical comparison
    }

    bool operator < (const string& s1, const string& s2){
        return (s2 > s1); // reuse greater than
    }

    bool operator >=(const string& s1, const string& s2){
        if(s1 == s2){ return true; } // equal case
        return s1 > s2; // greater than case
    }

    bool operator <=(const string& s1, const string& s2){
        if(s1 == s2){ return true; } // equal case
        return s2 > s1; //  less than case
    }

    string operator +(const string& s1, const string& s2){
        string ret_string(s1); // start with first string
        ret_string += s2; // append second string
        return ret_string;// return concatenated result
    }

    string operator +(const string& s1, const char addend[]){
        string ret_string(s1);  // start with first string
        ret_string += addend; // append C-string
        return ret_string; // return concatenated result
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