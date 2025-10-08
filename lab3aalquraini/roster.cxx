/*
 * CSEN 79 Lab Sample Code
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cassert>
#include "person.h"
#include "roster.h"


namespace csen79 {

	// STUDENT WORK
	Roster::Roster() {
		idx = 0;
		last = 0;
	}
	// insert into the roster
	void Roster::insert(const T &rec) {
		if(last >= CAPACITY){	//Checks if last will be out of bounds. if so throw an error for another function to catch
			throw std::out_of_range("No more space left in roster");
		}
		roster[last++] = rec;
	}

	// simply mark the slot empty
	void Roster::erase(Person::ID_t id) {
		bool is_found = false;

		for(int i = 0; i < last; i++){
			if(roster[i].getID() == id){
				for(int j = i; j < last-1; j++){
					roster[j] = roster[j+1];
				}
				is_found = true;
				last--;
				break;
			}
		}
		if(!is_found){throw std::invalid_argument("ID does not exist");}
	}

	// rudimentary iterator
	// in the future, this will return an object of iterator type
	Roster::T* Roster::begin(void) {
		return &roster[0];
	}

	Roster::T* Roster::end(void) {
		// STUDENT WORK
		return &roster[last];
	}

	// The next element for interation
	// if already reached the end, throw exception
	Roster::T* Roster::next(void) {
		if(idx >= last){
			idx = 0;
		}
		return &roster[++idx];
	}
}
