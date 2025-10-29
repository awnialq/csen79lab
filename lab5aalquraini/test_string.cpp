#include "mystring.h"
#include <iostream>

using namespace coen79_lab5

int main(){
    string default_str();
    string char_str('A');

    default_str += char_str;
    std::cout << default_str << std::endl;


    return EXIT_SUCCESS;
}