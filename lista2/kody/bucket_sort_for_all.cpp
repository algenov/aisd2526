#include "bucket_sorts.h"
#include "counters.h"
#include <cfloat>
#include <iostream>
using namespace std;

void bucket_sort_for_all(float list[], int n){
    // we need to scale numbers to [0,1) and then just call simple bucket_sort
    // when sorted we need to scale back to original range
    // so the main purpose is to find a range, which will scale numbers evenly

    float min_val;
    float max_val;
    min_val = list[0];
    c.assignments++;
    max_val = list[0];
    c.assignments++;  
    for (int i = 1; i < n; i++)
    {   
        c.comparisons++;
        if (list[i]<min_val){
            c.comparisons++;
            min_val = list[i];
            c.assignments++;
        }
        if (list[i]>max_val){
            c.comparisons++;
            max_val = list[i];
            c.assignments++;
        }
    }


    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        list[i] = (list[i] - min_val)/(max_val - min_val);
        c.assignments++;
    }
    c.comparisons++;
    if (max_val == min_val) {
        return;
    }
    bucket_sort(list, n);
    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        list[i] = list[i] * (max_val - min_val) + min_val;
        c.assignments++;
    }

    
}