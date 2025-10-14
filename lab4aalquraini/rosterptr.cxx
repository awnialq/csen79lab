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

namespace csen79 {
	// write code for all these
	RosterPtr::RosterPtr() {}
	RosterPtr::~RosterPtr() {}
	bool RosterPtr::insert(const T &rec) { return false; }
	void RosterPtr::erase(Person::ID_t id) { }
	Roster::T* RosterPtr::begin(void) { return nullptr; }
	Roster::T* RosterPtr::end(void) { return nullptr; }
	Roster::T* RosterPtr::next(void) {return nullptr; }


}	// namespace
