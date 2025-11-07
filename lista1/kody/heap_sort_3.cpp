#include <iostream>
#include <math.h>
#include "sort_stats.h"
using namespace std;

int left_3(int index){
    return 3*index + 1;
}

int middle(int index){
    return 3*index + 2;
}

int right_3(int index){
    return 3*index + 3;
}

SortStats heapify_3(int list[], int index, int heap_size, SortStats operations){
    int left_child_index = left_3(index);
    int middle_child_index = middle(index);
    int right_child_index = right_3(index);
    int largest_index = index;
    if (left_child_index < heap_size and list[left_child_index] > list[largest_index])
    {
        
        largest_index = left_child_index;
    }
    operations.comparison++;
    if (middle_child_index < heap_size and list[middle_child_index] > list[largest_index])
    {
        largest_index = middle_child_index;
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
        operations = heapify_3(list, largest_index, heap_size, operations);

    }
    operations.comparison++;
    return operations;
}

SortStats build_heap_3(int list[], int size, SortStats operations){
    for (int i = floor((size+1)/3)-1; i >= 0; i--){
        operations.comparison++;
        heapify_3(list, i, size, operations);
    }
    return operations;
}

SortStats heap_sort_3(int list[], int size){
    SortStats operations;
    operations = build_heap_3(list, size, operations);
    for (int i = size-1; i >= 1; i--){
        operations.comparison++;
        swap(list[0], list[i]);
        operations.assign++;
        operations = heapify_3(list, 0, i, operations);
    }
    return operations;
}

// int main() {
//     int size = 16;
//     int tab[size] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
//     cout << heap_sort_3(tab, size) << "\n";
//     for (int i = 0; i < size; i++){
//         cout << tab[i] << " ";
//     }
// }