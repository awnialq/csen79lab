#include "mystring.h"
#include <iostream>

using namespace coen79_lab5;

int main(){
    string default_str;
    std::cout << "Default string right after construction: " << default_str << std::endl;

    string char_str('A');
    std::cout << "Character string right after construction: " << char_str << std::endl;

    string moved_str;
    {
    string copy_constructor_str(char_str);
    std::cout << "Copy constructed string from character string: " << copy_constructor_str << std::endl;

    moved_str = std::move(copy_constructor_str);
    }
    std::cout << "Moved string from copy constructed string (og was deleted because it is out of scope): " << moved_str << std::endl;

    std::cout << "Enter a string (testing >> operator into default string): ";
    std::cin >> default_str;
    std::cout << "You entered: " << default_str << std::endl;
    std::cout << "Length of the entered string: " << default_str.length() << std::endl;
    std::cout << "First character of the entered string: " << default_str[0] << std::endl;
    std::cout << "Count of character 'a' in the entered string: " << default_str.count('a') << std::endl;
    std::cout << "Search for character 'e' in the entered string at index: " << default_str.search('e') << std::endl;
    std::cout << "Search for substring 'test' in the entered string at index: " << default_str.search(string("test")) << std::endl;
    std::cout << "After appending ' World' to the entered string using += operator: ";
    default_str += " World";
    std::cout << default_str << std::endl;
    char_str.insert(" A", 0);
    std::cout << "After inserting ' A' at position 0 in character string: " << char_str << std::endl;
    char_str.dlt(0, 2);
    std::cout << "After deleting 2 characters from position 0 in character string: " << char_str << std::endl;
    default_str.replace('Z', 0);
    std::cout << "After replacing character at position 0 with 'Z' in entered string: " << default_str << std::endl;
    default_str.replace("Replaced", 1);
    std::cout << "After replacing substring starting at position 1 with 'Replaced' in entered string: " << default_str << std::endl;
    default_str += char_str;
    std::cout << "After appending character string to the entered string using += operator: " << default_str << std::endl;

    string temp = default_str + char_str;
    std::cout << "After concatenation of default string with character string using + operator: " << temp << std::endl;

    default_str = "New Value";
    std::cout << "After assignment of a new value to default string using = operator: " << default_str << std::endl;

    default_str = 'A';
    std::cout << "After assignment of character 'A' to default string using = operator: " << default_str << std::endl;

    default_str = char_str + "BC";
    std::cout << "After assignment of default string to char string + BC using = operator: " << default_str << std::endl;

    default_str = char_str;
    std::cout << "Comparison of default string and character string after making them equal:";
    std::cout << (default_str == char_str ? " They are equal." : " They are not equal.") << std::endl;
    default_str = "Different Value";
    std::cout << "Comparison of default string and character string after changing default string:";
    std::cout << (default_str == char_str ? " They are equal." : " They are not equal.") << std::endl;

    std::cout << "Testing relational operators between default string and character string:" << std::endl;
    std::cout << "Current state of default_str: " << default_str << std::endl;
    std::cout << "Current state of char_str: " << char_str << std::endl;
    std::cout << (default_str != char_str ? "default_str != char_str is true." : "default_str != char_str is false.") << std::endl; 
    std::cout << (default_str < char_str ? "default_str < char_str is true." : "default_str < char_str is false.") << std::endl;
    std::cout << (default_str <= char_str ? "default_str <= char_str is true." : "default_str <= char_str is false.") << std::endl;
    std::cout << (default_str > char_str ? "default_str > char_str is true." : "default_str > char_str is false.") << std::endl;
    std::cout << (default_str >= char_str ? "default_str >= char_str is true." : "default_str >= char_str is false.") << std::endl;


    std::cout << "Testing out of range exceptions:" << std::endl;



    try{
        default_str.replace(char_str, 10); // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when replacing: " << e.what() << std::endl;
    }

    try{
        default_str.replace('B', 10); // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when replacing: " << e.what() << std::endl;
    }

    try{
        char c = default_str[10]; // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when accessing character: " << e.what() << std::endl;
    }

    try{
        default_str.insert("INSERTED", 50); // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when inserting: " << e.what() << std::endl;
    }

    try{
        default_str.dlt(0, 100); // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when deleting: " << e.what() << std::endl;
    }

    try{
        char c = default_str[100]; // Intentionally out of range
    }
    catch(const std::out_of_range& e){
        std::cout << "Caught purposeful out of range exception when accessing character again: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}