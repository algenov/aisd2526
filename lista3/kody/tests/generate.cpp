#include "../include/counters.hpp"
#include "../include/cut_rod.hpp"
#include "../include/LCS.hpp"
#include "../include/activity_selector.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// generators 

static vector<long long> gen_prices(int n, int seed) {
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(1, 100);
    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) p[i] = dist(rng);
    return p;
}

static vector<int> gen_seq(int n, int seed, int alphabet = 6) {
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, alphabet - 1);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = dist(rng);
    return v;
}

struct Activity { float s; float f; };

static void gen_activities_two_orders(
    int m, int seed,

    vector<float>& start_finish_sorted, vector<float>& finish_finish_sorted, 
    vector<float>& start_start_sorted,     vector<float>& finish_start_sorted      
) {
    mt19937 rng(seed);
    uniform_real_distribution<float> sdist(0.0f, 100000.0f);
    uniform_real_distribution<float> ddist(1.0f, 500.0f);

    vector<Activity> a(m);
    for (int i = 0; i < m; ++i) {
        float s = sdist(rng);
        float d = ddist(rng);
        a[i] = {s, s + d};
    }

    // start sorted
    {
        vector<Activity> b = a;
        sort(b.begin(), b.end(), [](const Activity& x, const Activity& y) {
            if (x.s != y.s) return x.s < y.s;
            return x.f < y.f;
        });

        start_start_sorted.resize(m);
        finish_start_sorted.resize(m);
        for (int i = 0; i < m; ++i) {
            start_start_sorted[i]  = b[i].s;
            finish_start_sorted[i] = b[i].f;
        }
    }

    // classic finish sorted with 0
    {
        vector<Activity> b = a;
        sort(b.begin(), b.end(), [](const Activity& x, const Activity& y) {
            if (x.f != y.f) return x.f < y.f;
            return x.s < y.s;
        });

        start_finish_sorted.assign(m + 1, -1.0f);
        finish_finish_sorted.assign(m + 1, -1.0f);
        start_finish_sorted[0] = -1.0f;
        finish_finish_sorted[0] = -1.0f;

        for (int i = 1; i <= m; ++i) {
            start_finish_sorted[i]  = b[i - 1].s;
            finish_finish_sorted[i] = b[i - 1].f;
        }
    }
}


// printing

static void print_row(
    const char* problem,
    const char* algo,
    int n,
    int seed,
    const Counters& c
) {
    cout << problem << "," << algo << "," << n << "," << seed
         << "," << c.cmp << "," << c.assign << "\n";
}

// runners

static void run_cut_rod_sizes(
    const vector<int>& naive_sizes,
    const vector<int>& dp_sizes,
    int seed
) {
    for (int n : naive_sizes) {
        auto prices = gen_prices(n, seed);
        Counters c;
        naive_cut_rod(prices.data(), n, c);
        print_row("CUT_ROD", "naive", n, seed, c);
    }

    for (int n : dp_sizes) {
        auto prices = gen_prices(n, seed);

        {
            vector<long long> best(n + 1, -1);
            vector<long long> how(n + 1, 0);
            Counters c;
            memorized_cut_rod(prices.data(), n, best.data(), how.data(), c);
            print_row("CUT_ROD", "memo", n, seed, c);
        }

        {
            vector<long long> best(n + 1, -1);
            vector<long long> how(n + 1, 0);
            Counters c;
            iter_cut_rod(prices.data(), n, best.data(), how.data(), c);
            print_row("CUT_ROD", "iter", n, seed, c);
        }
    }
}

static void run_lcs_sizes(const vector<int>& sizes, int seed) {
    for (int n : sizes) {
        auto X = gen_seq(n, seed);
        auto Y = gen_seq(n, seed + 5);

        {
            Counters c;
            auto table = lcs_iter(X.data(), Y.data(), n, n, c);
            (void)table;
            print_row("LCS", "iter", n, seed, c);
        }

        {
            Counters c;
            auto table = lcs_rec_table(X.data(), Y.data(), n, n, c);
            (void)table;
            print_row("LCS", "rec", n, seed, c);
        }
    }
}

static void run_activity_sizes(const vector<int>& sizes, int seed) {
    for (int m : sizes) {
        vector<float> start_g, finish_g;
        vector<float> start_dp, finish_start_sorted;

        gen_activities_two_orders(m, seed, start_g, finish_g, start_dp, finish_start_sorted);

        // finish sorted with 0
        {
            vector<int> res;
            Counters c;
            as_rec(start_g.data(), finish_g.data(), (int)start_g.size(), 0, res, c);
            print_row("ACTIVITY", "as_rec", m, seed, c);
        }

        // finish sorted with 0
        {
            Counters c;
            auto res = as_iter(start_g.data(), finish_g.data(), (int)start_g.size(), c);
            (void)res;
            print_row("ACTIVITY", "as_iter", m, seed, c);
        }

        // start sorted
        {
            Counters c;
            auto res = recursive_as_start_sorted(start_dp.data(), finish_start_sorted.data(), (int)start_dp.size(), c);
            (void)res;
            print_row("ACTIVITY", "start_sorted", m, seed, c);
        }
    }
}


// main

int main() {
    cout << "problem,algo,n,seed,cmp,assign\n";

    vector<int> cut_naive_sizes = {5, 8, 10, 12, 14, 16, 18, 25};
    vector<int> cut_dp_sizes    = {10, 2000, 3000, 5000, 8000, 10000};

    vector<int> lcs_sizes = {200, 400, 600, 1000, 1600, 2000};
    vector<int> act_sizes = {2000, 4000, 6000, 10000, 16000, 20000};

    int seed = 12345;

    run_cut_rod_sizes(cut_naive_sizes, cut_dp_sizes, seed);
    run_lcs_sizes(lcs_sizes, seed);
    run_activity_sizes(act_sizes, seed);

    return 0;
}
