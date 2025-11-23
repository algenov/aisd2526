#include "insertion_sort.h"
#include "bucket_sorts.h"
#include "counters.h"
#include <cmath>
void bucket_sort(float list[], int n){
    Node** buckets = new Node*[n];
    // create a table with pointers to the heads of linked lists

    for (int i = 0; i < n; i++)
    {
        buckets[i] = nullptr;
    }
    // make all heads nullptr
    
    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        int index = floor(n * list[i]); // index is determined by value scaled to [0, n-1]
        if (index < 0) index = 0;        // just in case of some weird float values
        if (index >= n) index = n - 1;
        c.assignments++; 
        append(buckets[index], list[i]);    // append value to appropriate bucket
        insertion_sort(buckets[index]); // sort the bucket after insertion
    }

    int index_for_final_list = 0;  
    for (int i = 0; i < n; i++)
    {
        c.comparisons++;
        if (buckets[i] != nullptr){
            c.comparisons++;
            Node* current = buckets[i];
            c.assignments++;
            while (current != nullptr)
            {
                c.comparisons++;
                list[index_for_final_list] = current->value;
                c.assignments++;
                index_for_final_list++;
                current = current->next;
            }
        }
    }

    delete[] buckets;
}