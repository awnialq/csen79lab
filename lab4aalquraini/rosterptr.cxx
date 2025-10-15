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
		capacity = 15;
		roster = new T[capacity];	//manually allocate memory to the array so you can dynamically size it
		idx = 0;
		last = 0;
	}
	RosterPtr::~RosterPtr() {
		delete [] roster;	// manually deallocate the whole array because we manually allocate it
	}
	bool RosterPtr::insert(const T &rec) { 
		if(last >= capacity){	//check if the array is full
			capacity = capacity * 2;	//double the current capacity
			
			T *temp = new T[capacity];	//make a new array to copy data over
			for(auto i = 0; i < last; i++){
				temp[i] = roster[i];	//copy the data
			}

			delete [] roster;	//deallocate the old sized array
			roster = temp;	// set roster to the new temp array (changes the pointer pretty much)
		}
		roster[last++] = rec;	//adds the element to the end of the available space
		return true;	//will always successfully add as there is no size limitation anymore
	 }
	void RosterPtr::erase(Person::ID_t id) {
		bool isFound = false;	//a flag to check if the item was found or not

		for(auto i = 0; i < last; i++){	//loop to check where the element exists
			if(roster[i].getID() == id){	//check if id matches
				for(auto j = i; j < last - 1; j++){	//shift everything down (effectively erases the element originally there)
					roster[j] = roster[j+1];
				}
				last--;	//decrements last so it matches up properly
				isFound = true;	//raise the flag
			}
		}

		if(!isFound) {throw std::invalid_argument("ID does not exist in the roster");}	//throw an ID not found error if the function fails to find the element
	}
	Roster::T* RosterPtr::begin(void) { 
		idx = 0;	//always reset idx to 0
		return &(roster[idx]);
	}
	Roster::T* RosterPtr::end(void) { 
		return &(roster[last]);	//return the last element in the array
	}
	Roster::T* RosterPtr::next(void) { 
		if (idx >= last)	//check if the iterator is out of bounds
			throw std::out_of_range("Roster iterator exceeded range: "+std::to_string(idx));
		return &(roster[++idx]);	//return the address to the element
	}


}	// namespace
