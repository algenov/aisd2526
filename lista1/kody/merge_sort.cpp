#include <iostream>
#include <math.h>
#include "sort_stats.h"
using namespace std;



SortStats merge(int list[], int begin, int middle, int end, SortStats number) {
    int len_left = middle - begin + 1;
    int len_right = end - middle;
    int left_list[len_left];
    int right_list[len_right];

    for (int i = begin; i < begin+len_left; i++) {
        number.comparison++;
        left_list[i-begin] = list[i];
        number.assign++;
    }

    for (int i = middle; i < middle+len_right; i++) {
        number.comparison++;
        right_list[i-middle] = list[i+1];
        number.assign++;
    }

    int left_index = 0;
    int right_index = 0;

    for (int i = begin; i <= end; i++) {
        number.comparison++;
        if ((left_index < len_left and left_list[left_index] <= right_list[right_index]) or right_index >= len_right){
            list[i] = left_list[left_index];
            left_index++;
            number.assign++;
        } else {
            list[i] = right_list[right_index]; 
            right_index++;
            number.assign++;
        }

        number.comparison++;
    }
    return number;
}

SortStats merge_sort(int list[], int begin, int end, SortStats number) {
    if (begin < end) {
        int middle = floor((begin+end)/2);
        number = merge_sort(list, begin, middle, number);
        number = merge_sort(list, middle+1, end, number);
        number = merge(list, begin, middle, end, number);
    }
    number.comparison++;
    return number;
}


// int main() {
//     int n = 16;
//     int tab[n] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
//     int number = 0;
//     number = merge_sort(tab, 0, 15, number);
//     cout << number;
//     cout << "\n";
//     for (int i = 0; i < n; i++) {
//         cout << tab[i] << " ";
//     }
// }
