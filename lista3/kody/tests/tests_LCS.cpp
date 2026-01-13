#include "../include/LCS.hpp"
#include <iostream>
#include <vector>

using namespace std;

int errors = 0;

bool same_vec(const vector<int>& a, const vector<int>& b) {
    if ((int)a.size() != (int)b.size()) return false;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void print_vec(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

// same backtracking as print_lcs, but returns vector so we can check
vector<int> get_lcs(const vector<vector<int>>& found_solution, int X[], int Y[], int len_X, int len_Y) {
    int lcs_length = found_solution[len_X][len_Y];
    vector<int> lcs(lcs_length);

    int index_X = len_X;
    int index_Y = len_Y;
    int index_lcs = lcs_length - 1;

    while (index_X > 0 and index_Y > 0) {
        if (X[index_X - 1] == Y[index_Y - 1]) {
            lcs[index_lcs] = X[index_X - 1];
            index_X--;
            index_Y--;
            index_lcs--;
        } else if (found_solution[index_X - 1][index_Y] > found_solution[index_X][index_Y - 1]) {
            index_X--;
        } else {
            index_Y--;
        }
    }

    return lcs;
}

void check_vec(const vector<int>& got, const vector<int>& expected, const char* algo) {
    if (same_vec(got, expected)) {
        cout << "  " << algo << ": OK\n";
    } else {
        cout << "  " << algo << ": fail\n";
        cout << "    got      = ";
        print_vec(got);
        cout << "\n    expected = ";
        print_vec(expected);
        cout << "\n";
        errors++;
    }
}

void run_test(
    const char* name,
    int X[],
    int Y[],
    int len_X,
    int len_Y,
    vector<int> expected
) {
    cout << "\ntest: " << name << "\n";

    cout << "X = ";
    print_vec(vector<int>(X, X + len_X));
    cout << "\nY = ";
    print_vec(vector<int>(Y, Y + len_Y));
    cout << "\nexpected = ";
    print_vec(expected);
    cout << "\n";

    // iter
    {
        Counters c;
        auto table = lcs_iter(X, Y, len_X, len_Y, c);
        auto got = get_lcs(table, X, Y, len_X, len_Y);

        check_vec(got, expected, "iter");

        cout << "  iter print: ";
        print_lcs(table, X, Y, len_X, len_Y, c);
        cout << "\n  iter cnt:   " << c << "\n";
    }

    // rec (memo)
    {
        Counters c;
        auto table = lcs_rec_table(X, Y, len_X, len_Y, c);
        auto got = get_lcs(table, X, Y, len_X, len_Y);

        check_vec(got, expected, "rec");

        cout << "  rec  print: ";
        print_lcs(table, X, Y, len_X, len_Y, c);
        cout << "\n  rec  cnt:   " << c << "\n";
    }
}


int main() {

    // test 1
    {
        int X[] = {1, 2, 3};
        int Y[] = {1, 2, 3};
        run_test("identical", X, Y, 3, 3, {1, 2, 3});
    }

    // test 2
    {
        int X[] = {1, 9, 2, 9, 3, 9, 4};
        int Y[] = {1, 2, 3, 4};
        run_test("Y is subsequence", X, Y, 7, 4, {1, 2, 3, 4});
    }

    // test 3
    {
        int X[] = {1, 2, 3};
        int Y[] = {4, 5, 6};
        run_test("no common", X, Y, 3, 3, {});
    }

    // test 4
    {
        int X[] = {7, 7, 7, 7};
        int Y[] = {7, 7};
        run_test("repeats", X, Y, 4, 2, {7, 7});
    }

    // test 5
    {
        int X[] = {1, 3, 4, 1, 2, 3};
        int Y[] = {3, 4, 1, 2, 1, 3};
        run_test("classic", X, Y, 6, 6, {3, 4, 1, 2, 3});
    }

    cout << "\n\n";
    if (errors == 0) {
        cout << "all passed\n";
    } else {
        cout << "failed: " << errors << "\n";
    }

    return 0;
}
