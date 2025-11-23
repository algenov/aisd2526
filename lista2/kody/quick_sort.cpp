#include "partition.h"
#include "quick_sorts.h"
#include "counters.h"


void quick_sort(int list[], int begin, int end){
    c.comparisons++;
    if (begin<end){
        int divider = partition(list, begin, end);
        quick_sort(list, begin, divider-1);
        quick_sort(list, divider+1, end);
    }
}

