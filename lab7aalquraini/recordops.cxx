/*
 * Sin-Yaw Wang <swang24@scu.edu>
 * CSEN 79 Lab7 STL Algorithms
 * 
 * In this file, we recommend, that you implement the operators and member
 * functions for class Records
 */
#include <iostream>
#include "record.h"

namespace csen79 {

    bool Record::operator==(const struct tm &time){
        return birth.tm_mon == time.tm_mon;
    }
    bool Record::operator==(const std::pair<std::string, std::string> &fNameLname){
        return (first == fNameLname.first) && (last == fNameLname.second);
    }

    bool Record::operator<(const Record &rec){
        return last < rec.last;
    }
}