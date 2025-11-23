#include "radix_sorts.h"
#include "counters.h"

void radix_sort_neg(int list[], int n, int base){
    int count_pos = 0;
    int count_neg = 0;
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        c.comparisons++;
        if (list[i]>=0){
            count_pos++;
            c.comparisons++;
            if (list[i]>max){
                max = list[i];
                c.assignments++;
            }
        } else {
            count_neg++;
            c.comparisons++;
            if (list[i]<min){
                min = list[i];
                c.assignments++;
            }
        }
    }
    // count positive and negative numbers, find max and min

    int pos_list[count_pos];
    int neg_list[count_neg];

    int pos_index = 0;
    int neg_index = 0;

    while (neg_index < count_neg or pos_index < count_pos)
    {
        c.comparisons++;
        c.comparisons++;
        if (list[pos_index + neg_index] >= 0){
            pos_list[pos_index] = list[pos_index + neg_index];
            c.assignments++;
            pos_index++;
        } else {
            neg_list[neg_index] = -list[pos_index + neg_index];
            c.assignments++;
            neg_index++;
        }
    }
    // separate positive and negative numbers, negate negative numbers

    radix_sort(pos_list, count_pos, base);
    radix_sort(neg_list, count_neg, base);

    for (int i = 0; i < count_neg; i++)
    {
        c.comparisons++;
        list[i] = -neg_list[count_neg - 1 - i]; // negate back and reverse order
        c.assignments++;
    }
    for (int i = 0; i < count_pos; i++)
    {
        c.comparisons++;
        list[i + count_neg] = pos_list[i];  // copy positive numbers
        c.assignments++;
    }

}

