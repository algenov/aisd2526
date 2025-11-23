#include "counting_sort.h"
#include "radix_sorts.h"
#include "counters.h"


void radix_sort(int list[], int n, int base){
    int max = list[0];
    c.assignments++;
    for (int i = 1; i < n; i++)
    {   
        c.comparisons++;
        c.comparisons++;
        if (list[i]>max){
            max = list[i];
            c.assignments++;
        }
    }
    // find max element to know number of digits

    int max_digits = 0;
    while (max>0){
        c.comparisons++;
        max = max/base;
        c.assignments++;
        max_digits++;
    }
    // find number of digits in max element

    int exp = 1;
    for (int i=0; i<max_digits; i++){
        c.comparisons++;
        counting_sort(list, n, base, exp);
        exp = exp * base;
    }
    // do counting sort for every digit

}

