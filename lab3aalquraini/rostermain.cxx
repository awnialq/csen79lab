/*
 * CSEN 79 Lab 3 Class Roster - main tester file
 * Name: Awni AlQuraini
 * Email: aalquraini@scu.edu
 */
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <cassert>
#include "person.h"
#include "roster.h"

using namespace std;
using namespace csen79;

// Test code for class roster
// Input file: <CMD> [ID] [FIRST LAST]
// CMD : A | X | L
// ID: 7-digit unsigned integer
// FIRST, LAST: string
int main() {
	Roster r;
	Person st;
	Person::ID_t id;
	string cmd, first, last;

	// Read cmd first, then branch accordingly
	while (cin >> cmd) {
		switch (cmd[0]) {
		case Command::Add:
			cin >> id;		//parse the id, first, and last name in the row
			cin >> first;
			cin >> last;
			try	//try inserting the person 
			{
				r.insert(Person(id, first, last));
			}
			catch(const std::exception& e) // if there is no space catch the exception and print out the exception
			{
				cout << e.what() << endl;
			}
			break;
		case Command::Erase:
			cin >> id;	//parse the id you want to delete in the row
			try
			{
				r.erase(id); //try to erase that id
			}
			catch(const std::exception& e) // if the id does not exist catch the exception and print out the exception
			{
				cout << e.what() << endl;	
			}
			break;
		case Command::Print:
			// listing the entire roster with a rudimentary iterator
			cout << "---- Current Roster ----"  << endl;
			int i = 1;
			for (auto st = r.begin(); st != r.end(); st = r.next(), i++)
				cout << i << ": " << *st << endl;
			break;
		} 
	}
	
	return EXIT_SUCCESS;
}

