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

    struct cmpBMI{
    const bool operator()(const Record &rec1, const Record &rec2) {
        return rec1.getBMI() < rec2.getBMI();
    }
};

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

    //finding if "Lily Liu" exists in the dataset

    std::pair<std::string, std::string> lilyLiu;
    lilyLiu.first = "Lily";
    lilyLiu.second = "Liu";

    std::string found = (std::find(records.begin(), records.end(), lilyLiu) != records.end()) ? "yes" : "no";

    cout << "\nIs \"Lily Liu\" in the dataset?: " << found << endl;

    //print the students out after sorting it by last name

    std::sort(records.begin(), records.end());

    cout << "\nSorted by last name in ascending order: " << endl;

    it = records.begin();
    while(it != records.end()){
        cout << "\t" << *it << endl;
        ++it;
    }

    //print the students out in ascending order of bmi

    cmpBMI bmiFunctor;
    
    cout << "\nSorted by BMI in ascending order: " << endl;

    std::sort(records.begin(), records.end(), bmiFunctor);

    it = records.begin();
    while(it != records.end()){
        cout << "\t" << *it << endl;
        ++it;
    }

    return EXIT_SUCCESS;
}