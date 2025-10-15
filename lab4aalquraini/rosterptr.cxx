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

// if array fills allocate new mem and copy over the array to the larger size


namespace csen79 {
	// write code for all these
	RosterPtr::RosterPtr() {
		capacity = 30;
		roster = new T[capacity];
		idx = 0;
		last = 0;
	}
	RosterPtr::~RosterPtr() {
		delete [] roster;
	}
	bool RosterPtr::insert(const T &rec) { 
		if(last >= 30){
			capacity = capacity * 2;
			
			T *temp = new T[capacity];
			for(auto i = 0; i < last; i++){
				temp[i] = roster[i];
			}
			delete [] roster;
			roster = temp;
		}
		roster[last++] = rec;
		return true;
	 }
	void RosterPtr::erase(Person::ID_t id) {
		bool isFound = false;

		for(auto i = 0; i < last; i++){
			if(roster[i].getID() == id){
				for(auto j = i; j < last - 1; j++){
					roster[j] = roster[j+1];
				}
				last--;
				isFound = true;
			}
		}

		if(!isFound) {throw std::invalid_argument("ID does not exist in the roster");}
	}
	Roster::T* RosterPtr::begin(void) { 
		idx = 0;
		return &(roster[idx++]);
	}
	Roster::T* RosterPtr::end(void) { 
		return &(roster[last]);	
	}
	Roster::T* RosterPtr::next(void) { 
		return &(roster[++idx]);
	}


}	// namespace
