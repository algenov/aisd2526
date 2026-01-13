#include "../include/activity_selector.hpp"
#include <iostream>
#include <vector>

using namespace std;

int errors = 0;

void check_vec(const vector<int>& got,
               const vector<int>& expected,
               const char* algo)
{
    if (got == expected) {
        cout << "  " << algo << ": OK\n";
    } else {
        cout << "  " << algo << ": fail\n";
        errors++;
    }
}

bool is_valid_schedule(const vector<int>& sol, float start[], float finish[]) {
    for (size_t k = 1; k < sol.size(); ++k) {
        int prev = sol[k - 1];
        int cur  = sol[k];
        if (start[cur] < finish[prev]) return false;
    }
    return true;
}

void run_test(
    const char* name,
    float start[],
    float finish[],
    int n,
    const vector<int>& expected
) {
    cout << "\ntest: " << name << "\n";

    //  recursive
    {
        vector<int> res;
        Counters c;
        as_rec(start, finish, n, 0, res, c);
        check_vec(res, expected, "as_rec");
    }

    //  iterative
    {
        Counters c;
        vector<int> res = as_iter(start, finish, n, c);
        check_vec(res, expected, "as_iter");
    }

    // original
    // this method doesn't always give the most obvious solution but it is correct
    {
    Counters c;
    vector<int> res = recursive_as_start_sorted(start, finish, n, c);

    // remove 0 if it exists
    if (!res.empty() && res[0] == 0) {
        res.erase(res.begin());
    }

    if ((int)res.size() == (int)expected.size() && is_valid_schedule(res, start, finish)) {
        cout << "  dp_n2: OK\n";
    } else {
        cout << "  dp_n2: fail\n";
        errors++;
    }
    }
}

int main() {

    // classic finish-sorted example
    // finish[0] = -1
    // expected: 1,2,4,5
    float start[]  = {-1, 1, 3, 0, 5, 8, 5};
    float finish[] = {-1, 2, 4, 6, 7, 9, 9};

    run_test(
        "classic finish-sorted",
        start,
        finish,
        7,
        {1,2,4,5}
    );

    cout << "\n";
    if (errors == 0)
        cout << "all passed\n";
    else
        cout << "failed: " << errors << "\n";

    return 0;
}
