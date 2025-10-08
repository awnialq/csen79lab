/*
*   Name: Awni AlQuraini
*   Lab Section: CSEN79L-2
*   File: part2.cpp
*   Implements part 2 of Lab 1
*/
#include <iostream>
#include <iomanip>

int main(){
    std::string s = "0123456789";   //the regular string
    std::string s_rev = "9876543210";   //the reversed version of the string

    int w1 = 14;    //amount of width needed for the first string s
    int w2 = 20;    //amount of line width needed for the second string s_rev

    for(int i = 0; i < 5; i++){     //Prints each string 5 times
        std::cout << std::setw(w1) << s << std::setw(w2) << s_rev << std::endl;
        
        w1 += 2;    //the width for each string gets increased by two each time the loop runs
        w2 += 2;
    }

    return 0;
}