/*
 * CSEN 79 Lab Sample Code
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include "person.h"
#include "roster.h"
#include "rosterptr.h"

/*
*   Instructions to other tester: 
*       Using the makefile provided, compile the program. After doing so, prepare your own test file in a similar format to lab4test.txt
*       Then, exectue the program like so: ./rosterptrtest < [the name of your test file] > output.log
*       After doing so, go through output.log to see what the program outputs and compare it to your expected behaviour
*       Make sure to test removing non-existent ids to see how the program handles them.
*       This testing function should handle this testing flow.
*/

namespace csen79 {

void RosterPtr::testRoster() {
    Person t;
	std::string cmd;

	// Read cmd first, then branch accordingly
    while (std::cin >> cmd) {
        switch (cmd[0]) {
        case Command::Add:
            // Insert a record
            std::cin >> t;
            try {
                this->insert(t); // insert returns if successful
            } catch (std::out_of_range &e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case Command::Erase: {
            // remove a record, given the ID
            Person::ID_t id;
            std::cin >> id;
            try{
                this->erase(id);
            }
            catch (std::invalid_argument &e){
                std::cout << e.what() << std::endl;
                break;
            }
            std::cout << "Erase " << id << std::endl;
            }
            break;
        case Command::Print:
            // listing the entire roster with a rudimentary iterator
            std::cout << "---- Current Roster ----"  << std::endl;
            int i = 1;
            for (auto st = this->begin(); st != this->end(); st = this->next(), i++)
                std::cout << i << ": " << *st << std::endl;
            break;
        }
    }
}

}   // namespace