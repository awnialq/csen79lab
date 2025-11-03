/*
 * CSEN 79 Lab
 * <YOUR NAME HERER>
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "roster.h"
#include "rosterllist.h"

namespace csen79 {
	// STUDENT WORKS
	// IMPLEMENT ALL THESE FUNCTIONS
	// These are code only to make the program compile.  They do not work!
	RosterLList::RosterLList() {}
	RosterLList::~RosterLList() {}
	RosterLList::Node::Node(){}
	RosterLList::Node::Node(T &t){}
	RosterLList::Node::~Node(){}
	RosterLList::iterator RosterLList::begin(){return RosterLList::iterator(nullptr); }
	RosterLList::iterator RosterLList::end(){return RosterLList::iterator(nullptr); }
	bool RosterLList::insert(T &rec) {return false;}
	void RosterLList::erase(Person::ID_t id) {}

	RosterLList::iterator::iterator(Node *t) {}
	bool RosterLList::iterator::operator !=(const iterator &rhs) {return false;}
	Roster::T &RosterLList::iterator::operator *() { return ptr->data; }
	RosterLList::iterator &RosterLList::iterator::operator++() {return *this; }
}
