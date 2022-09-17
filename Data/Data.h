
#ifndef INC_2_4_0_DATA_H
#define INC_2_4_0_DATA_H

#include <string>

class Data {
public:
    std::string nickname;
    unsigned int rank;
    unsigned int experience;
    unsigned int donate;

    Data();

    ~Data() = default;

    friend std::ostream& operator<< (std::ostream& out, const Data& d);

    friend bool operator< (const Data &d1, const Data &d2);

    friend bool operator> (const Data &d1, const Data &d2);

    friend bool operator== (const Data &d1, const Data &d2);
};

#endif
