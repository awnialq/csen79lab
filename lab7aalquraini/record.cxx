/*
 * Sin-Yaw Wang <swang24@scu.edu>
 * CSEN 79 Lab7 STL Algorithms
 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include "record.h"
namespace csen79 {

/*
 * The input/output operators for Record.
 * There should be no need to modify these
 */
std::istream &operator>>(std::istream &is, Record &r) {
    int y, m;
    if (is >> r.first >> r.last >> r.birth.tm_year >> r.birth.tm_mon >> r.birth.tm_mday >> r.weight >> r.height) {
        r.birth.tm_year -= Record::EpochYear;
        r.birth.tm_mon -= 1;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Record &r) {
    os << r.first << " " << r.last;
    char birthday[std::size("yyyy/mmm/dd")];
    strftime(birthday, std::size(birthday), "%Y/%h/%d", &r.birth);
    os << " " << birthday;
    os << " " << std::fixed << std::setprecision(1) << r.weight << "lb";
    os << " " << r.height/12 << "\'"<< r.height % 12 << "\"";
    return os;
}
}