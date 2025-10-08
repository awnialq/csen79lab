/*
*   Name: Awni AlQuraini
*   Lab Section: CSEN79L-2
*   File: part3.cpp
*   Implements part 3 of Lab 1
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

int main(int argc, char *argv[]){
    std::vector<std::string> stringList;    //dynamicly sized array to help with storing the words that meet the criteria
    std::ifstream file(argv[1]);    //reads the text file arg
    assert(file.is_open()); //makes sure the file is actually open
    std::string word;   //the words that will be read

    /*
    *   This loop reads every word in the file to the word variable for processing in the loop
    */

    while(file >> word){
        std::string cleanWord = "";
        for(char c : word){     //Strips all the punctuation out of a word
            if(!(std::ispunct(c))){
                cleanWord += c;
            }
        }
        word = cleanWord;

        if(word.length() >= 10){    //Makes sure each character is uppercase in the word
            for(int i = 0; i < (int)word.length(); i++){
                word[i] = toupper(word[i]); 
            }
            stringList.push_back(word); //Adds the word to the stringList vector
        }
    }

    file.close();   //closes the filestream

    for(std::string s : stringList){    //prints out all the strings in the stringList vector
        std::cout << s << std::endl;
    }
}