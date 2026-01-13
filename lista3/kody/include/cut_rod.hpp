#pragma once

#include "counters.hpp"

long long naive_cut_rod(long long prices[], int n, Counters& cnt);

long long memorized_cut_rod(long long prices[], int n, long long best_prices[], long long how_to_cut[], Counters& cnt);

long long iter_cut_rod(long long prices[], int n, long long best_prices[], long long how_to_cut[], Counters& cnt);

void print_solution(int n, const long long how_to_cut[]);