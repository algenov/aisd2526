#include <iostream>
#include <math.h>
#include "sort_stats.h"
using namespace std;

int left(int index){
    return 2*index + 1;
}

int right(int index){
    return 2*index + 2;
}

SortStats heapify(int list[], int index, int heap_size, SortStats operations){
    int left_child_index = left(index);
    int right_child_index = right(index);
    int largest_index = index;
    if (left_child_index < heap_size and list[left_child_index] > list[largest_index])
    {
        largest_index = left_child_index;
    }
    operations.comparison++;
    if (right_child_index < heap_size and list[right_child_index] > list[largest_index])
    {
        largest_index = right_child_index;
    }
    operations.comparison++;
    if (largest_index != index)
    {
        swap (list[index], list[largest_index]);
        operations.assign++;
        operations = heapify(list, largest_index, heap_size, operations);

    }
    operations.comparison++;
    return operations;
}

SortStats build_heap(int list[], int size, SortStats operations){
    for (int i = floor(size/2)-1; i >= 0; i--){
        operations.comparison++;
        operations = heapify(list, i, size, operations);
    }
    return operations;
}

SortStats heap_sort(int list[], int size){
    SortStats operations = {0,0};
    operations = build_heap(list, size, operations);
    for (int i = size-1; i >= 1; i--){
        operations.comparison++;
        swap (list[0], list[i]);
        operations.assign++;
        operations = heapify(list, 0, i, operations);
    }
    return operations;
}

// int main(){
//     int size = 16;
//     int tab[size] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
//     int operations = 0;
    
//     cout << heap_sort(tab, size) << "\n";
//     for (int i = 0; i < size; i++){
//         cout << tab[i] << " ";
//     }
// }