#pragma once

struct Counters {
    long long comparisons = 0;
    long long assignments = 0;

    void reset() {
        comparisons = 0;
        assignments = 0;
    }
};

// one global object but somewhere else
extern Counters c;