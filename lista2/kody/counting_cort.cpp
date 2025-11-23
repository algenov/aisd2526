#include "counting_sort.h"
#include "counters.h"

void counting_sort(int list[], int n, int base, int exp){
    
    int* output = new int[n];
    int* count  = new int[base];
    // create two tables, one for outpur, second to count occurences
    
    for (int i = 0; i < base; i++)
    {
        count[i] = 0;
    }
    // initialize count table with 0
    
    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        int digit = (list[i]/exp) % base;
        c.assignments++;
        count[digit]++;
    }
    // every digit in count table gets number of occurences
    
    for (int i=1; i < base; i++){
        c.comparisons++;
        count[i] = count[i] + count[i-1];
        c.assignments++;
    }
    // every digit in count table gets position in output table, but enlarged by 1(if el must be on the 0 place in list it gets 1 in count table)
    
    for (int i=n-1; i>=0; i--){
        c.comparisons++;
        int digit = (list[i]/exp) % base;
        c.assignments++;
        output[count[digit]-1] = list[i]; // -1 to adjust position
        c.assignments++;
        count[digit]--; // decrease count for next occurence of the same digit
        c.assignments++;
    }
    // build output table

    for (int i=0; i<n; i++){
        c.comparisons++;
        list[i] = output[i];
        c.assignments++;
    }
    // copy output to original list

    delete[] output;
    delete[] count;

}