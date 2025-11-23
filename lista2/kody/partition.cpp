#include "partition.h"
#include <iostream>
#include "counters.h"
using namespace std;

int partition(int list[], int begin, int end){
    int x = list[end];
    c.assignments++;
    int i = begin-1;
    
    for (int j=begin; j<end; j++){
        c.comparisons++;
        c.comparisons++;
        if (list[j]<=x){
            i = i + 1;
            swap(list[i], list[j]);
            c.assignments++;
        }
    }
    swap(list[i+1], list[end]);
    c.assignments++;
    return i+1;
}
