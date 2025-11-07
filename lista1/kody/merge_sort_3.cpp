#include <iostream>
#include <math.h>
#include "sort_stats.h"
using namespace std;


SortStats merge_3(int list[], int begin, int middle1, int middle2, int end, SortStats number) {
    int len_left = middle1 - begin + 1;
    int len_middle = middle2 - middle1;
    int len_right = end - middle2;

    int left_list[len_left];
    int middle_list[len_middle];
    int right_list[len_right];

    for (int i = begin; i < begin+len_left; i++) {
        number.comparison++;
        left_list[i-begin] = list[i];
        number.assign++;
    }
    for (int i = middle1; i < middle1+len_middle; i++) {
        number.comparison++;
        middle_list[i-middle1] = list[i+1];
        number.assign++;
    }
    for (int i = middle2; i < middle2+len_right; i++) {
        number.comparison++;
        right_list[i-middle2] = list[i+1];
        number.assign++;
    }

    int left_index = 0;
    int middle_index = 0;
    int right_index = 0;
    int main_index = begin;
    bool left_valid, middle_valid, right_valid;
    int minimum;
    while (left_index + middle_index + right_index <= len_left+len_middle+len_right-1){ 
        number.comparison++;
        if (left_index < len_left) {
            left_valid = true;
        } else {
            left_valid = false;
        }
        number.comparison++;
        if (middle_index < len_middle) {
            middle_valid = true;
        } else {
            middle_valid = false;
        }
        number.comparison++;
        if (right_index < len_right) {
            right_valid = true;
        } else {
            right_valid = false;
        }
        number.comparison++;
        if (left_valid and middle_valid and right_valid) {
            minimum = left_list[left_index];
            number.assign++;
            left_index++;
            if (middle_list[middle_index] < minimum and right_list[right_index] < minimum) {
                left_index--;
                if (middle_list[middle_index] < right_list[right_index]) {
                    minimum = middle_list[middle_index];
                    number.assign++;
                    middle_index++;
                } else {
                    minimum = right_list[right_index];
                    number.assign++;
                    right_index++;
                }
                number.comparison++;

            }else if (middle_list[middle_index] < minimum) {
                minimum = middle_list[middle_index];
                number.assign++;    
                middle_index++;
                left_index--;

            }else if (right_list[right_index] < minimum) {
                minimum = right_list[right_index];
                number.assign++;
                right_index++;
                left_index--;
            }
            number.comparison = number.comparison + 3; // dla wszystkich if
            
        } else if (left_valid and middle_valid) {
            minimum = left_list[left_index];
            number.assign++;
            left_index++;
            if (middle_list[middle_index] < minimum) {
                minimum = middle_list[middle_index];
                number.assign++;
                middle_index++;
                left_index--;
            }
        } else if (left_valid and right_valid) {
            minimum = left_list[left_index];
            number.assign++;
            left_index++;
            if (right_list[right_index] < minimum) {
                minimum = right_list[right_index];
                number.assign++;
                right_index++;
                left_index--;
            }
        } else if (middle_valid and right_valid) {
            minimum = middle_list[middle_index];
            number.assign++;
            middle_index++;
            if (right_list[right_index] < minimum) {
                minimum = right_list[right_index];
                number.assign++;
                right_index++;
                middle_index--;
            }
        } else if (left_valid) {
            minimum = left_list[left_index];
            number.assign++;
            left_index++;
        } else if (middle_valid) {
            minimum = middle_list[middle_index];
            number.assign++;
            middle_index++;
        } else if (right_valid) {
            minimum = right_list[right_index];
            number.assign++;
            right_index++;
        }
        number.comparison = number.comparison + 7; // dla wszystkich if

        list[main_index] = minimum;
        number.assign++;
        main_index++;

    }
    return number;
    
}

SortStats merge_sort_3(int list[], int begin, int end, SortStats number){
    int first_middle, second_middle;
    if (begin < end-1)
    {
        first_middle = begin + floor((end-begin)/3);
        second_middle = begin + floor((end - begin)*2/3);
        number = merge_sort_3(list, begin, first_middle, number);
        number = merge_sort_3(list, first_middle+1, second_middle, number);
        number = merge_sort_3(list, second_middle+1, end,  number);
        number = merge_3(list, begin, first_middle, second_middle, end, number);
    }
    else {  
        int a = list[begin];
        number.assign++;
        int b = list[end];
        number.assign++;
        if (a > b){
            list[begin] = b;
            number.assign++;
            list[end] = a;
            number.assign++;
        }
        number.comparison++;
    }
    number.comparison++;
    return number;
}



// int main() {
//     int list[] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
//     int size = sizeof(list)/sizeof(list[0]);
//     // merge_sort_3(list, 0, size-1);
//     // for (int i = 0; i < size; i++) {
//     //     cout << list[i] << " ";
//     // }
//     cout << merge_sort_3(list, 0, 15, 0) << "\n";
//     for (int i = 0; i < size; i++) {
//         cout << list[i] << " ";
//     }
//     return 0;
// }