/*
*   Name: Awni AlQuraini
*   Lab Section: CSEN79L-2
*   File: part1.cpp
*   Implements part 1 of Lab 1
*/
#include <iostream>

int main(){
    std::string input; //variable that holds the input of the user

    int alphaNum = 0;   //variable that holds the alpha numeric characters
    int nonAlpha = 0;   //variable that holds the non alphanumeric characters

    std::cout << "Please type something:" << std::endl; //prompts the user to say something
    getline(std::cin, input);   //Takes the whole user input including whitespaces


    for(int i = 0; i < (int)input.length(); i++){
        if((int)input.at(i) == 32){ continue; } //ensures the whitespace character is not read
        std::isalnum(input.at(i)) == 0 ? nonAlpha++ : alphaNum++;   //a ternary statement to determine what numbers are alphanumeric using the isalnum function in std::
    }

    std::cout << "\""<< input << "\" has " << alphaNum << " alphanumeric characters and " << nonAlpha << " non-alphanumeric characters." << std::endl;   //Formatted output
}