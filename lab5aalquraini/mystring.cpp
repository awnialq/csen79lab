#include <cstring>
#include <iostream>
#include "mystring.h"


namespace coen79_lab5{

    string::string(const char str[] = "") {
        current_length = std::strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        std::strcpy(characters, str);
    }

    string::string(char c) {
        current_length = 1;
        allocated = 2; // one for character and one for null terminator
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }

    string::string(const string& source){

    }

    string::~string(){
        if((characters == nullptr)) { return; }
        delete [] characters;
    }

    void string::operator +=(const string& addend){

    }

    void string::operator +=(const char addend[]){

    }

    void string::operator +=(char addend){

    }

    void string::reserve(size_t n){

    }

    string& string::operator =(const string& source){

    }

    void string::insert(const string& source, unsigned int position){

    }

    void string::dlt(unsigned int position, unsigned int num){

    }

    void string::replace(char c, unsigned int position){

    }

    void string::replace(const string& source, unsigned int position){

    }

    char string::operator [](size_t position) const{

    }

    int string::search(char c) const{

    }

    int string::search(const string& substring) const{

    }

    unsigned int string::count(char c) const{

    }

    std::ostream& operator <<(std::ostream& outs, const string& source){

    }

    bool operator ==(const string& s1, const string& s2){

    }

    bool operator !=(const string& s1, const string& s2){

    }

    bool operator > (const string& s1, const string& s2){

    }

    bool operator < (const string& s1, const string& s2){

    }

    bool operator >=(const string& s1, const string& s2){

    }

    bool operator <=(const string& s1, const string& s2){

    }

    string operator +(const string& s1, const string& s2){

    }

    string operator +(const string& s1, const char addend[]){

    }

    std::istream& operator >> (std::istream& ins, string& target){

    }
}