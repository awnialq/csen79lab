/*
 * CSEN 79 Lab 6 - Main Tester
 * Instructions on how to write the tester class:
 * 	1. In order to write this tester, you must utilize the commands defined in roster.h (Erase = 'X', Add = 'A', Print = 'L')
 *	2. Read from an input stream (std::cin) the commands and branch accordingly
 *	3. For 'A' command, read a Person object from the input stream and insert it into the RosterLList object
 *	4. For 'X' command, read a Person::ID_t from the input stream and erase the corresponding Person object from the RosterLList object
 *	5. For 'L' command, print the entire roster using the iterator defined in RosterLList
 *  6. Handle exceptions where necessary
 * 	7. Edgecases should be tested in the lab3sampleinput.txt file (Removing head)
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "roster.h"
#include "rosterllist.h"

using namespace std;
using namespace csen79;

int main() {
	RosterLList r;
    r.testRoster();
	return EXIT_SUCCESS;
}

