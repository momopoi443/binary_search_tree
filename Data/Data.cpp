
#include "Data.h"
#include <random>
#include <iostream>

Data::Data() {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<unsigned int> dist(0, 1'000'000'000);

    nickname = "username";
    rank = 0;
    experience = dist(mt);
    donate = 0;
}

std::ostream& operator<< (std::ostream& out, const Data& d) {
    out
            << "Nickname: " << d.nickname << std::endl
            << "Rank: " << d.rank << std::endl
            << "Experience: " << d.experience << std::endl
            << "Donate: " << d.donate << std::endl;
    return out;
}

bool operator< (const Data &d1, const Data &d2) {
    return d1.experience < d2.experience;
}

bool operator> (const Data &d1, const Data &d2) {
    return d1.experience > d2.experience;
}

bool operator==(const Data &d1, const Data &d2) {
    return d1.experience == d2.experience;
}
