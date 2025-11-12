//
// main.cpp
// PROVIDES: A test file for deque and its iterator
//
//  CSEN 79
//  --- Behnam Dezfouli, CSEN, SCU ---

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <cassert>
#include "deque_iterator.h" // The iterator class for deque (refer to file deque_iterator.h)
#include "deque.h"

using namespace csen79_lab8;
using std::cout;

int main(void) {
    
    int test_number = 0;
    
    // ------------- Test: constructor -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing constructor...!\n";
    deque<int> myDeque1;
    cout << "Done!\n\n";
    
    
    // ------------- Test: push_back() and back() -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing push_back() and back()...!\n";
    for (int i = 0; i < 100; ++i)
    {
        myDeque1.push_back(i);
        cout << myDeque1.back() << " ";
    }
    cout << "\n" << "Done!\n\n";
    
    
    // ------------- Test: push_front() and front() -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing push_front() and front()...!\n";
    for (int i = 0; i < 100; ++i)
    {
        myDeque1.push_front(i);
        cout << myDeque1.front() << " ";
    }
    cout << "\n" << "Done!\n\n";

    
    // ------------- Test: iterator -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing iterator...!\n";
    for (auto it = myDeque1.begin(); it != myDeque1.end(); ++it)
        cout << *it << " ";
    cout << "\n" << "Done!\n\n";

    
    // ------------- Test: pop_front() -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing pop_front()...!\n";
    for (int i = 0; i < 100; ++i)
    {
        myDeque1.pop_front();
    }
    cout << "\nFront is: " << myDeque1.front();
    cout << "\nBack is: " << myDeque1.back();
    cout << "\n" << "Done!\n\n";
    
    
    // ------------- Test: pop_back() -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing pop_back()...!\n";
    for (int i = 0; i < 10; ++i)
    {
        myDeque1.pop_back();
    }
    cout << "\nFront is: " << myDeque1.front();
    cout << "\nBack is: " << myDeque1.back();
    cout << "\n" << "Done!\n\n";

    
    // ------------- Test: iterator -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing iterator...!\n";
    for (auto it = myDeque1.begin(); it != myDeque1.end(); ++it)
        cout << *it << " ";
    cout << "\n" << "Done!\n\n";

    
    
    // ------------- Test: assignment operator -------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing assignment operator...!\n";
    deque<int> myDeque2;
    myDeque2.push_front(3);
    myDeque2.push_front(2);
    myDeque2.push_front(1);
    myDeque2.push_back(4);
    myDeque2.push_back(5);
    myDeque2.push_back(6);
    
    deque<int> myDeque3;
    myDeque3 = myDeque2;
    
    for (auto it = myDeque3.begin(); it != myDeque3.end(); ++it)
        cout << *it << " ";
    
    cout << "\n" << "Done!\n\n";
    
    
    
    // ------------- Test: copy constructor-------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing copy constructor...!\n";
    deque<int> myDeque4(myDeque3);

    for (auto it = myDeque4.begin(); it != myDeque4.end(); ++it)
        cout << *it << " ";
    cout << "\n" << "Done!\n\n";


    // ------------- Test: iterator-------------
    cout << "Test number: " << ++test_number << "\n";
    cout << "Testing iterator...!\n";
    auto it_start = myDeque4.begin();
    auto it_end = myDeque4.end();
    auto it2 = it_start;
    
    
    while(it2 != it_end)
    {
        *it2 = 950;
        ++it2;
    }
    
    
    it2 = it_start;
    
    while(it2 != it_end)
    {
       cout << *it2 << " ";
        it2++;
    }
    cout << "\n" << "Done!\n\n";
    
    return EXIT_SUCCESS;
}
