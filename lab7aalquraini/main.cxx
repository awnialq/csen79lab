/*
 * Sin-Yaw Wang <swang24@scu.edu>
 * CSEN 79 Lab7 STL Algorithms
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "record.h"

namespace csen79 {

// Here you declare/define BMI comparitor and the class for the functor

}

using namespace std;
using namespace csen79;

int main(void) {

    // read in all lines from stdin.
    // run with stdin redirection
    // Otherwise, open a file and replace cin with a ifstream
    string line;
    vector<Record> records;
    while (getline(cin, line)) {
        std::stringstream sio(line);
        Record r;
        if (sio >> r)
            records.push_back(r);
    }

    //finding people who were born in march

    cout << "People born in March: " << endl;
    auto it = records.begin();
    struct tm *march = (struct tm*)malloc(sizeof(struct tm));
    march->tm_mon = 2;
    while(it != records.end()){
        it = std::find(it, records.end(), *march);
        if(it != records.end()){
            cout << "\t" << *it << endl;
            ++it;
        }
    }

    return EXIT_SUCCESS;
}