#include <iostream>
#include "partition.h"
#include "quick_sorts.h"
#include "counters.h"
using namespace std;

// najpierw bierzemy dwa elementy dzieliacych tablice, dlatego mozna wziąć dwa elementy na końcu, porównać ich, najpierw zrobic partition dla mniejszego, potem dla większego



void quick_sort_2_divider(int list[], int begin, int end){
    c.comparisons++;
    if (begin<end){
        int divider1, divider2;
        c.comparisons++;
        if (list[end]<list[end-1]){
            swap(list[end], list[end-1]);
            c.assignments++;
        } 
        divider1 = partition(list, begin, end-1);
        divider2 = partition(list, divider1+1, end);
        quick_sort_2_divider(list, begin, divider1-1);
        quick_sort_2_divider(list, divider1+1, divider2-1);
        quick_sort_2_divider(list, divider2+1, end);
    }
}

