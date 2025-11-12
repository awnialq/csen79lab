// FILE: deque.h
// PROVIDES: A class for deque (double ended queue)
// Belongs to namespace csen79_lab8
//
//  CSEN 79
//  Behnam Dezfouli, CSEN, SCU
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the deque<Item> class:
//   The template parameter, Item, is the data type of the items in the deque,
//   also defined as deque<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   deque<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a deque.
//
//   static const size_t BLOCK_SIZE = ____
//     deque::BLOCK_SIZE is the number of enteries in each data block
//
//   static const size_t BLOCKPOINTER_ARRAY_SIZE = ____
//     deque::BLOCKPOINTER_ARRAY_SIZE is the number of enteries in the array of block pointers
//
//   typedef ____ Item
//     sequence::Item is the data type of the items in the deque. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and a copy constructor.
//
//
// CONSTRUCTOR for the deque<Item> class:
//   deque(size_type init_bp_array_size = BLOCKPOINTER_ARRAY_SIZE,
//         size_type initi_block_size = BLOCK_SIZE);
//     Postcondition: The deque contains an array of block pointers with BLOCKPOINTER_ARRAY_SIZE entries
//     NOTE: The default value for the init_bp_array_size is BLOCKPOINTER_ARRAY_SIZE.
//     The default value for the initi_block_size is BLOCK_SIZE.
//
//
//
// CONST MEMBER FUNCTIONS for the deque<Item> class:
//
//   bool isEmpty()
//     Postcondition: Returns false if the deque is empty.
//     Otherwise returns true.
//
//   value_type front()
//    Precondition: isItem() must return true.
//    Postcondition: Returns a copy of the front item.
//
//   value_type back()
//    Precondition: isItem() must return true.
//    Postcondition: Returns a copy of the back item.
//
//
// MEMBER FUNCTIONS for the deque<Item> class:
//   void clear()
//     Postcondition: All the entries of the deque are deleted.
//
//   void print()
//     Postcondition: Prints all the entries of the deque.
//
//   void reserve()
//    Postcondition: Increases the capacity of the deque by 20 x BLOCK_SIZE
//
//   void push_front(const value_type& entry)
//    Postcondition: Adds entry to the front of the deque
//
//   void push_back(const value_type& entry)
//    Postcondition: Adds entry to the back of the deque
//
//   void pop_front()
//    Precondition: isItem() must return true
//    Postcondition: Removes the front item of the deque
//
//   void pop_back()
//    Precondition: isItem() returns true
//    Postcondition: Removes the back item of the deque
//
//
// VALUE SEMANTICS for the deque<Item> class:
//    Assignments and the copy constructor may be used with deque objects.
//
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   iterator end( )

#ifndef CSEN79_DEQUE
#define CSEN79_DEQUE

//#define USEDEBUG

#include <algorithm> // For std::copy

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace csen79_lab8
{
    template <class Item>
    class deque {
    public:
        
        static const size_t BLOCK_SIZE = 5; // Number of data items per data block
        static const size_t BLOCKPOINTER_ARRAY_SIZE = 5; // Number of entries in the array of block pointers (The minimum acceptable value is 2)
        
        // type aliases
        using size_type  = std::size_t;
        using value_type = Item; // The type of items stored in the deque
        using iterator = deque_iterator<Item>; // A typedef to simplify the use of iterator class
        
        // CONSTRUCTOR and DESTRUCTOR
        deque(size_type init_bp_array_size = BLOCKPOINTER_ARRAY_SIZE, size_type initi_block_size = BLOCK_SIZE);
        deque(const deque& source);
        ~deque();
        // Skip move operator.  Default to assignment
        void operator=(const deque& source);
        
        // CONST MEMBER FUNCTIONS
        bool isEmpty() const;
        value_type front() const;
        value_type back() const;
        
        // ITERATOR MEMBER FUNCTIONS
        iterator begin();
        iterator end();

        // MODIFICATION MEMBER FUNCTIONS
        void clear();
        void reserve();
        void push_front(const value_type& entry);
        void push_back(const value_type& entry);
        void pop_back();
        void pop_front();
        
        
    private:
        
        value_type** block_pointers;      // A pointer to the array of block pointers
        value_type**  block_pointers_end; // A pointer to the final entry in the array of block pointers
        
        value_type**  first_bp;  // A pointer to the entry of the array of block pointers which points to the first data block
        value_type**  last_bp;   // A pointer to the entry of the array of block pointers which points to the last data block
        
        value_type* front_ptr;   // A pointer to the front element of the deque
        value_type* back_ptr;    // A pointer to the back element of the deque
        
        size_type bp_array_size; // Number of entries in the array of block pointers
        size_type block_size;    // Number of entries in each data block
    };
    
}
#include "deque.impl"
#endif /* deque_hpp */
