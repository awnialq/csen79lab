// FILE: deque_iterator.h
// PROVIDES: A class for deque iterator (non-const)
//
// CSEN 79
// Copyright © 2016 Behnam Dezfouli. All rights reserved.
// CSEN, SCU
//
// FORWARD ITERATOR to step through the items of a deque
// A deque_iterator can change the underlying deque list through the
// * operator.
// WARNING:
// This classes use std::iterator as its base class;
// Older compilers that do not support the std::iterator class can
// delete everything after the word iterator


#ifndef deque_iterator_h
#define deque_iterator_h

namespace csen79_lab8
{
    template <class Item>
    class deque_iterator
    {
        
    public:
        using size_type = std::size_t;
        using value_type = Item;
        
        // CONSTRUCTOR
        deque_iterator(value_type** initial_block_pointers = nullptr, value_type**  initial_block_pointers_end = nullptr,
                       value_type**  initial_first_bp = nullptr, value_type**  initial_last_bp = nullptr,
                       value_type* initial_front_ptr = nullptr, value_type* initial_back_ptr = nullptr,
                       size_type initial_bp_array_size = 0, size_type initial_block_size = 0,
                       value_type* initial_cursor = nullptr, value_type* initial_current_boundary = nullptr, value_type** initial_current_block_pointer = nullptr) :

            block_pointers{initial_block_pointers},
            block_pointers_end{initial_block_pointers_end},
            first_bp{initial_first_bp},
            last_bp{initial_last_bp},
            front_ptr{initial_front_ptr},
            back_ptr{initial_back_ptr},
            bp_array_size{initial_bp_array_size},
            block_size{initial_block_size},
            cursor{initial_cursor},
            current_block_pointer{initial_current_block_pointer},
            current_boundary{initial_current_boundary} {}
        
        /*
         * Explicitly make these default for readability.
         * Note the default is shallow copying.
         */
        deque_iterator(const deque_iterator &) = default;
        deque_iterator &operator=(const deque_iterator &) = default;
        deque_iterator &operator=(deque_iterator &&) = default;
        ~deque_iterator() = default;

        // CONST MEMBER FUNCTIONS
        value_type& operator *() const { return *cursor; }
        bool operator !=(const deque_iterator other) const { return !(*this == other); }
        bool operator ==(const deque_iterator &other) const;
        
        // MODIFICATION MEMBER FUNCTIONS
        deque_iterator& operator ++(); // Prefix ++
        deque_iterator operator ++(int); // Postfix ++
        
        
    private:
        // A pointer to the dynamic array of block pointers
        value_type** block_pointers;
        
        // A pointer to the final entry in the array of block pointers
        value_type**  block_pointers_end;
        
        
        // A pointer to the first block pointer that’s now being used
        value_type**  first_bp;
        
        // A pointer to the last block pointer that’s now being used
        value_type**  last_bp;
        
        value_type* front_ptr; // A pointer to the front element of the whole deque
        
        value_type* back_ptr;  // A pointer to the back element of the whole deque
        
        size_type bp_array_size; // Number of entries in the array of block pointers
        size_type block_size; // Number of entries in each block of items
        
        
        // NOTE: Up to this point, the set of pointer variables is similar to the deque class, the
        //       following pointers enable the itertor to move forward and point to the next item.
        
        value_type* cursor; // A pointer to the "current" item
        value_type** current_block_pointer; // A pointer to the data block that includes the item the "cursor" is pointing to
        value_type* current_boundary; // A pointer to the end of the data block the "cursor" is pointing to
    };
}

#include "deque_iter.impl"
#endif /* deque_iterator_h */
