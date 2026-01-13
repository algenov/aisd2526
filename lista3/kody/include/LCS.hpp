#pragma once
#include <vector>
#include "counters.hpp"


// iterative
std::vector<std::vector<int>> lcs_iter(int X[], int Y[], int len_X, int len_Y, Counters& c);

// fills memo[len_X][len_Y]
int lcs_rec(int X[], int Y[], int len_X, int len_Y, std::vector<std::vector<int>>& memo, Counters& c);

// recursive main func
std::vector<std::vector<int>> lcs_rec_table(int X[], int Y[], int len_X, int len_Y, Counters& c);

// works for iter and rec
void print_lcs(const std::vector<std::vector<int>>& found_solution, int X[], int Y[], int len_X, int len_Y, Counters& c);
