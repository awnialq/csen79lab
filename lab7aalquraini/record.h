/*
 * Sin-Yaw Wang <swang24@scu.edu>
 * CSEN 79 Lab7 STL Algorithms
 * 
 * The Record Class
 * The BMI comparitor function and the class for the functor comparito should be friends to this class.
 */
#ifndef RECORD_H
#define RECORD_H

namespace csen79 {

class Record {
public:
    static constexpr int EpochYear = 1900;
    const float getBMI() const { return weight / height / height * 703;}
    
    bool operator==(const struct tm &month);
    bool operator==(const std::pair<std::string, std::string> &fNameLname);
    bool operator<(const Record &rec);

private:
    std::string first;
    std::string last;
    struct tm birth;
    float weight;
    int height;

friend std::istream &operator>>(std::istream &, Record &);
friend std::ostream &operator<<(std::ostream &, const Record &);

// Examples of friending the function and functor class
// friend const bool BMIless(const Record &lh, const Record &rh);
// friend class HeightLess;
};

}
#endif // RECORD_H