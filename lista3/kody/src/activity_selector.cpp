#include "../include/activity_selector.hpp"
#include <vector>
using namespace std;

// finish[0] should be -1
vector<int> as_rec(
    float start[],
    float finish[],
    int len_finish,
    int current_finish_id,
    vector<int>& final_vector,
    Counters& cnt
) {
    int lesson_start_runner = current_finish_id + 1;
    cnt.assign++;

    while (lesson_start_runner <= len_finish-1 and start[lesson_start_runner] < finish[current_finish_id]) {
        lesson_start_runner++;
    }

    cnt.cmp++;
    if (lesson_start_runner <= len_finish-1) {
        final_vector.push_back(lesson_start_runner);
        as_rec(start, finish, len_finish, lesson_start_runner, final_vector, cnt);
        return final_vector;
    }
    else {
        return final_vector;
    }
}

vector<int> as_iter(
    float start[],
    float finish[],
    int len_finish,
    Counters& cnt
) {
    vector<int> final_vector;
    final_vector.push_back(1); // we always take the first lesson (push_back doesn't count)

    int current_finish_id = 1;
    cnt.assign++;

    for (int runner=2; runner <= len_finish-1; runner++) {
        cnt.cmp++;
        if (start[runner] >= finish[current_finish_id]) {
            final_vector.push_back(runner); // push_back doesn't count
            current_finish_id = runner;
            cnt.assign++;
        }
    }
    return final_vector;
}


// the best option if we start from i
int best_from(
    int i,
    const float start[],
    const float finish[],
    int n,
    vector<int>& best_len_from_i,
    vector<int>& next_choice,
    Counters& cnt
) {
    cnt.cmp++;
    if (best_len_from_i[i] != -1) return best_len_from_i[i];

    int best_len = 1;      // the miinimum is to take this one
    cnt.assign++;
    int best_next = -1;
    cnt.assign++;

    for (int j = i + 1; j < n; ++j) {
        cnt.cmp++;
        if (start[j] >= finish[i]) {
            int cand = 1 + best_from(j, start, finish, n, best_len_from_i, next_choice, cnt);
            cnt.assign++;

            cnt.cmp++;
            if (cand > best_len) {
                best_len = cand;
                cnt.assign++;
                best_next = j;
                cnt.assign++;
            }
        }
    }

    best_len_from_i[i] = best_len;
    cnt.assign++;
    next_choice[i] = best_next;
    cnt.assign++;

    return best_len;
}

vector<int> recursive_as_start_sorted(
    const float start[],
    const float finish[],
    int n,
    Counters& cnt
) {
    cnt.cmp++;
    if (n <= 0) return {};

    vector<int> best_len_from_i(n, -1);
    vector<int> next_choice(n, -1);

    // count our previous function for every possible start
    for (int i = 0; i < n; ++i) {
        best_from(i, start, finish, n, best_len_from_i, next_choice, cnt);
    }

    // choose the best starting point
    int best_start = 0;
    cnt.assign++;

    for (int i = 1; i < n; ++i) {
        cnt.cmp++;
        if (best_len_from_i[i] > best_len_from_i[best_start]) {
            best_start = i;
            cnt.assign++;
        }
    }

    // recreate the solution
    vector<int> result;
    for (int cur = best_start; cur != -1; cur = next_choice[cur]) {
        result.push_back(cur); // push_back
    }

    return result;
}
