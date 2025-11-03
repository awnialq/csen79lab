/*
 * CSEN 79 Lab 6 - Main Tester
 * Instructions on how to write the tester class:
 * 	1. In order to write this tester, you must utilize the commands defined in roster.h (Erase = 'X', Add = 'A', Print = 'L')
 *	2. 
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

