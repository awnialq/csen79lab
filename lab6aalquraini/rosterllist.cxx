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
		head = nullptr;	//set the head to nullptr as there is nothing in the list yet
	}
	RosterLList::~RosterLList() {
		while(head != nullptr){	//keep on deleting until the end of the linked list
			Node *temp = head;
			head = head->next;
			delete temp; 
		}
	}

	RosterLList::Node::Node(){
		next = nullptr;	//set the nest variable in the node to nullptr. no data to assign
	}
	RosterLList::Node::Node(T &t){
		data = t;	// set the data to the passed student
		next = nullptr;	//set the next variable to nullptr
	}
	RosterLList::Node::~Node(){}	// no memory allocation required so no need to define a body


	RosterLList::iterator RosterLList::begin(){
		return RosterLList::iterator(head);	//return an iterator with head as its internal pointer
	}

	RosterLList::iterator RosterLList::end(){
		return RosterLList::iterator(nullptr);	//return nullptr as that is the end of the linked list
	}

	bool RosterLList::insert(T &rec) {
		if(head == nullptr){	// check if head is null
			head = new Node(rec);	///if it is then insert there
			head->next = nullptr;
			return true;
		}
		Node *n = head;	//set a temp variable to hand iteration

		while(n->next != nullptr){	// while you are not at the end of the linked list, go to the next node
			n = n->next;
		}

		n->next = new Node(rec);	//set the next (which should be nullptr) to a new Node with the passed record.
		return true;
	}

	void RosterLList::erase(Person::ID_t id) {
		if (head == nullptr) {return;}	//if head is null id can't be there so just leave

		if(head->data.getID() == id){	//if the head has the ID, we have special code to handle it
			Node *temp = head;
			head = head->next;
			delete temp;
			return; // leave when done
		}	

		/*
		*	This logic handles deletion when the head is not the ID
		*/

		Node *n = head;
		while(n != nullptr && n->next != nullptr){
			if(n->next->data.getID() == id){
				Node *temp = n->next;
				n->next = n->next->next;
				delete temp;
				return;
			}
			n = n->next;
		}
	}

	RosterLList::iterator::iterator(Node *t) {	//very trivial iterator constructor
		ptr = t;
	}
	bool RosterLList::iterator::operator !=(const iterator &rhs) {	//compares two iterator types
		return !(this->ptr == rhs.ptr);
	}
	Roster::T &RosterLList::iterator::operator *() { return ptr->data; }	//returns the data inside the internal pointer using the dereference
	RosterLList::iterator &RosterLList::iterator::operator++() {
		ptr = ptr->next;	//go to the next node in the linked list
		return *this; //return the object itself.
	}
}
