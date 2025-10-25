#include <iostream>
#include <math.h>
using namespace std;



int merge(int list[], int begin, int middle, int end, int number) {
    int len_left = middle - begin + 1;
    int len_right = end - middle;
    int left_list[len_left];
    int right_list[len_right];
    for (int i = begin; i < begin+len_left; i++) {
        left_list[i-begin] = list[i];
        number++;


    }

    
    // for (int i = 0; i<len_left; i++){
    //     cout << left_list[i] << "\n";
    // }
    

    for (int i = middle; i < middle+len_right; i++) {
        right_list[i-middle] = list[i+1];
        number++;


    }
    // for (int i = 0; i<len_right; i++){
    //     cout << right_list[i] << "\n";
    // }

    int left_index = 0;
    int right_index = 0;

    for (int i = begin; i <= end; i++) {
        if ((left_index < len_left and left_list[left_index] <= right_list[right_index]) or right_index >= len_right){
            list[i] = left_list[left_index];
            left_index++;
            number++;

        }
        else {
            list[i] = right_list[right_index]; 
            right_index++;
            number++;

        }
        
    }
    return number;

}

int merge_sort(int list[], int begin, int end, int number) {
    if (begin < end) {
        int middle = floor((begin+end)/2);
        number = merge_sort(list, begin, middle, number);
        number = merge_sort(list, middle+1, end, number);
        number = merge(list, begin, middle, end, number);
    }
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
