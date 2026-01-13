#include "../include/LCS.hpp"
#include <iostream>
#include <vector>
using namespace std;


// iterative
vector<vector<int>> lcs_iter(int X[], int Y[], int len_X, int len_Y, Counters& c){
    vector<vector<int>> found_solution(len_X + 1, vector<int>(len_Y + 1));

    // just fill the first row and column with zeros
    for (int i = 0; i <= len_X; i++){
        c.assign++;
        found_solution[i][0] = 0;
    }
    for (int j = 0; j <= len_Y; j++){
        c.assign++;
        found_solution[0][j] = 0;
    }

    // fill the rest of the table
    for (int i = 1; i <= len_X; i++){   // for each character in X
        for (int j = 1; j <= len_Y; j++){  // for each character in Y
            c.cmp++;
            if (X[i - 1] == Y[j - 1]){  // if the characters match our lcs is longer by 1
                c.assign++;
                found_solution[i][j] = found_solution[i - 1][j - 1] + 1;
            }
            else{   // otherwise take the best of the two possibilities
                c.cmp++;
                if (found_solution[i - 1][j] >= found_solution[i][j - 1]){
                    c.assign++;
                    found_solution[i][j] = found_solution[i - 1][j];
                }
                else{
                    c.assign++;
                    found_solution[i][j] = found_solution[i][j - 1];
                }
            }
        }
    }
    return found_solution;
}


// fills memo[len_X][len_Y]
int lcs_rec(int X[], int Y[], int len_X, int len_Y, vector<vector<int>>& memo, Counters& c){
    c.cmp++;
    c.cmp++;
    if (len_X == 0 || len_Y == 0){
        return 0;
    }

    // if already in table
    c.cmp++;
    if (memo[len_X][len_Y] != -1){
        return memo[len_X][len_Y];
    }

    c.cmp++;
    if (X[len_X - 1] == Y[len_Y - 1]){
        c.assign++;
        memo[len_X][len_Y] = lcs_rec(X, Y, len_X - 1, len_Y - 1, memo, c) + 1;
    }
    else{   // otherwise take the best of the two possibilities
        int a = lcs_rec(X, Y, len_X - 1, len_Y, memo, c);
        int b = lcs_rec(X, Y, len_X, len_Y - 1, memo, c);

        c.cmp++;
        if (a >= b){
            c.assign++;
            memo[len_X][len_Y] = a;
        }
        else{
            c.assign++;
            memo[len_X][len_Y] = b;
        }
    }

    return memo[len_X][len_Y];
}


// recursive main func
vector<vector<int>> lcs_rec_table(int X[], int Y[], int len_X, int len_Y, Counters& c){
    vector<vector<int>> memo(len_X + 1, vector<int>(len_Y + 1, -1));

    // fill borders with zeros
    for (int i = 0; i <= len_X; i++){
        c.assign++;
        memo[i][0] = 0;
    }
    for (int j = 0; j <= len_Y; j++){
        c.assign++;
        memo[0][j] = 0;
    }

    // compute the answer and fill needed cells
    lcs_rec(X, Y, len_X, len_Y, memo, c);

    return memo;
}


// works for iter and rec
void print_lcs(const vector<vector<int>>& found_solution, int X[], int Y[], int len_X, int len_Y, Counters& c){
    int lcs_length = found_solution[len_X][len_Y];
    vector<int> lcs(lcs_length);

    int index_X = len_X;
    int index_Y = len_Y;
    int index_lcs = lcs_length - 1;

    while (index_X > 0 and index_Y > 0){
        c.cmp++;
        if (X[index_X - 1] == Y[index_Y - 1]){
            c.assign++;
            lcs[index_lcs] = X[index_X - 1];
            index_X--;
            index_Y--;
            index_lcs--;
        }
        else{
            c.cmp++;
            if (found_solution[index_X - 1][index_Y] > found_solution[index_X][index_Y - 1]){
                index_X--;
            }
            else{
                index_Y--;
            }
        }
    }

    for (int i = 0; i < lcs_length; i++){
        cout << lcs[i] << " ";
    }
}
