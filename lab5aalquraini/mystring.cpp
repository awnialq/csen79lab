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