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
	RosterLList::RosterLList() {
		head = nullptr;
	}
	RosterLList::~RosterLList() {
		if(head != nullptr){ delete head;}
	}

	RosterLList::Node::Node(){
		next = nullptr;
	}
	RosterLList::Node::Node(T &t){
		data = t;
		next = nullptr;
	}
	RosterLList::Node::~Node(){
		if(next != nullptr){
			delete next;
		}
	}


	RosterLList::iterator RosterLList::begin(){
		return RosterLList::iterator(head);
	}

	RosterLList::iterator RosterLList::end(){
		return RosterLList::iterator(nullptr);
	}

	bool RosterLList::insert(T &rec) {
		if(head == nullptr){
			head = new Node(rec);
			head->next = nullptr;
			return true;
		}
		Node *n = head;

		while(n->next != nullptr){
			n = n->next;
		}

		n->next = new Node(rec);
		return true;
	}

	void RosterLList::erase(Person::ID_t id) {
		if(head == nullptr){
			return;
		}
		if(head->data.getID() == id){
			delete head;
			head = head->next;
		}
		Node *n = head;
		while(n->next != nullptr){
			if(n->next->data.getID() == id){
				Node *temp = n->next;
				n->next = n->next->next;
				delete temp;
				break;
			}
			n = n->next;
		}
	}

	RosterLList::iterator::iterator(Node *t) {
		ptr = t;
	}
	bool RosterLList::iterator::operator !=(const iterator &rhs) {
		return !(this->ptr == rhs.ptr);
	}
	Roster::T &RosterLList::iterator::operator *() { return ptr->data; }
	RosterLList::iterator &RosterLList::iterator::operator++() {
		ptr = ptr->next;
		return *this; 
	}
}
