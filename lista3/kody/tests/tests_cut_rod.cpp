#include "../include/cut_rod.hpp"
#include <iostream>

using namespace std;

int errors = 0;

void check(long long got, long long expected, const char* algo) {
    if (got == expected) {
        cout << "  " << algo << ": OK\n";
    } else {
        cout << "  " << algo << ": fail (got " << got
             << ", expected " << expected << ")\n";
        errors++;
    }
}

void run_test(
    const char* name,
    long long prices[],
    int n,
    long long expected
) {
    cout << "\ntest: " << name << "\n";
    cout << "n = " << n << "\nprices = [";
    for (int i = 1; i <= n; i++) {
        cout << prices[i];
        if (i < n) cout << ", ";
    }
    cout << "]\n";
    cout << "expected = " << expected << "\n";

    // naive
    {
        Counters c;
        long long res = naive_cut_rod(prices, n, c);
        check(res, expected, "naive");
    }

    // memo
    {
        long long best[20];
        long long how[20];
        for (int i = 0; i <= n; i++) {
            best[i] = -1;
            how[i] = 0;
        }

        Counters c;
        long long res = memorized_cut_rod(prices, n, best, how, c);
        check(res, expected, "memo");
    }

    // iter
    {
        long long best[20];
        long long how[20];
        for (int i = 0; i <= n; i++) {
            best[i] = -1;
            how[i] = 0;
        }

        Counters c;
        long long res = iter_cut_rod(prices, n, best, how, c);
        check(res, expected, "iter");
    }
}

int main() {

    // test 1
    // n = 1
    // answer = prices[1]
    long long prices1[] = {0, 7};
    run_test("n = 1, trivial", prices1, 1, 7);

    // test 2
    // n = 2
    // best = 5 (не резать)
    long long prices2[] = {0, 1, 5};
    run_test("n = 2, no cut", prices2, 2, 5);

    // test 3
    // n = 4
    // best = 10 (2 + 2)
    long long prices3[] = {0, 1, 5, 8, 9};
    run_test("n = 4, classic", prices3, 4, 10);

    // test 4
    // n = 7
    // best = 18
    long long prices4[] = {0, 1, 5, 8, 9, 10, 17, 17};
    run_test("n = 7, classic", prices4, 7, 18);

    // test 5
    long long prices5[] = {0, 1, 5, 8, 100};
    run_test("n = 4, no cut is best", prices5, 4, 100);

    cout << "\n\n";
    if (errors == 0) {
        cout << "all passed\n";
    } else {
        cout << "failed: " << errors << "\n";
    }

    return 0;
}
