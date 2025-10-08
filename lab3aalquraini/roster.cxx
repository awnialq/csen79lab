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
		for(int i = 0; i < CAPACITY; i++){
			roster[i] = Person();
		}
		idx = 0;
		last = 0;
	}
	// insert into the roster
	void Roster::insert(const T &rec) {
		if(last > CAPACITY){	//Checks if last will be out of bounds. if so throw an error for another function to catch
			throw ("Index out of bounds error");
		}
		roster[last++] = rec;
	}

	// simply mark the slot empty
	void Roster::erase(Person::ID_t id) {
		while(idx < CAPACITY){
			if(roster[idx].getID() == id){
				roster[idx] = Person();
				break;
			}
			idx++;
		}
	}

	// rudimentary iterator
	// in the future, this will return an object of iterator type
	Roster::T* Roster::begin(void) {
		// STUDENT WORK
		return nullptr;
	}

	Roster::T* Roster::end(void) {
		// STUDENT WORK
		return nullptr;
	}

	// The next element for interation
	// if already reached the end, throw exception
	Roster::T* Roster::next(void) {
		// STUDENT WORK
		return nullptr;
	}
}
