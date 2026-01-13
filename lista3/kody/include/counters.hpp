#pragma once
#include <ostream>


struct Counters {
    long long cmp    = 0;  
    long long assign = 0;  

    void reset() {

        cmp = 0;
        assign = 0;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Counters& c) {
    os << "cmp=" << c.cmp
       << ", assign=" << c.assign;
    return os;
}
