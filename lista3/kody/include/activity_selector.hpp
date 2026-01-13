#pragma once
#include "counters.hpp"
#include <vector>


// finish[0] should be -1
std::vector<int> as_rec(
    float start[],
    float finish[],
    int len_finish,
    int current_finish_id,
    std::vector<int>& final_vector,
    Counters& cnt
);

std::vector<int> as_iter(
    float start[],
    float finish[],
    int len_finish,
    Counters& cnt
);



// sorted by start
int best_from(
    int i,
    const float start[],
    const float finish[],
    int n,
    std::vector<int>& best_len_from_i,
    std::vector<int>& next_choice,
    Counters& cnt
);

std::vector<int> recursive_as_start_sorted(
    const float start[],
    const float finish[],
    int n,
    Counters& cnt
);
