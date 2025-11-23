#include "sorts.h"
#include <iostream>
#include <cmath>
using namespace std;

bool is_sorted_int(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) return false;
    }
    return true;
}

bool is_sorted_float(float a[], int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i] + 1e-6f) return false;
    }
    return true;
}

void copy_int_array(int dst[], int src[], int n) {
    for (int i = 0; i < n; ++i) dst[i] = src[i];
}

void copy_float_array(float dst[], float src[], int n) {
    for (int i = 0; i < n; ++i) dst[i] = src[i];
}

void print_int_array(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        cout << " ";
    }
}

void print_float_array(float a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        cout << " ";
    }
}

// QUICK SORT TESTS
void run_quick_sort_tests() {
    cout << "quick_sort tests" << endl;

    const int tests_number = 10;
    const int max_length = 12;

    int data[tests_number][max_length] = {
        {5,4,3,2,1,9,8,7,6},                
        {10,7,8,9,1,5,2,3},                 
        {1,9,2,8,3,7,4,6,5},                
        {3,1,4,1,5,9,2,6},                  
        {9,9,8,8,7,7,6,6,5},                
        {4,3,2,7,8,9,2,3,4,5},              
        {99,1,50,23,77,10,11,5,4,3,2,1},    
        {15,14,13,12,11,10,9,8,7,6},        
        {5,1,3,9,8,2,4,7,6,0,11},           
        {42,17,8,23,99,1,0,4,3,55,30,18}    
    };

    int sizes[tests_number] = {9,8,9,8,9,10,12,10,11,12};

    for (int t = 0; t < tests_number; ++t) {
        int a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        quick_sort(a, 0, sizes[t]-1);
        cout << "test " << t << ": " << (is_sorted_int(a, sizes[t]) ) << endl;
    }
}

// QUICK SORT 2 DIVIDER TESTS
void run_quick_sort_2_divider_tests() {
    cout << "quick_sort_2_divider tests" << endl;

    const int tests_number = 10;
    const int max_length = 12;

    int data[tests_number][max_length] = {
        {5,4,3,2,1,9,8,7,6},                
        {10,7,8,9,1,5,2,3},                 
        {1,9,2,8,3,7,4,6,5},                
        {3,1,4,1,5,9,2,6},                  
        {9,9,8,8,7,7,6,6,5},                
        {4,3,2,7,8,9,2,3,4,5},              
        {99,1,50,23,77,10,11,5,4,3,2,1},    
        {15,14,13,12,11,10,9,8,7,6},        
        {5,1,3,9,8,2,4,7,6,0,11},           
        {42,17,8,23,99,1,0,4,3,55,30,18}    
    };

    int sizes[tests_number] = {9,8,9,8,9,10,12,10,11,12};

    for (int t = 0; t < tests_number; ++t) {
        int a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        quick_sort_2_divider(a, 0, sizes[t]-1);
        cout << "test " << t << ": " << (is_sorted_int(a, sizes[t]) ) << endl;
    }
}

// RADIX SORT TESTS
void run_radix_sort_tests() {
    cout << "radix_sort tests" << endl;

    const int tests_number = 10;
    const int max_length = 12;

    int data[tests_number][max_length] = {
        {170,45,75,90,802,24,2,66},                
        {10,7,8,9,1,5,2,3},                 
        {1,9,2,8,3,7,4,6,5},                
        {3,1,4,1,5,9,2,6},                  
        {9,9,8,8,7,7,6,6,5},                
        {4,3,2,7,8,9,2,3,4,5},              
        {99,1,50,23,77,10,11,5,4,3,2,1},    
        {15,14,13,12,11,10,9,8,7,6},        
        {5,1,3,9,8,2,4,7,6,0,11},           
        {42,17,8,23,99,1,0,4,3,55,30,18}    
    };

    int sizes[tests_number] = {8,8,9,8,9,10,12,10,11,12};

    for (int t = 0; t < tests_number; ++t) {
        int a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        radix_sort(a, sizes[t], 10);
        cout << "test " << t << ": " << (is_sorted_int(a,sizes[t]) ) << endl;
    }
}

// RADIX SORT NEGATIVE TESTS
void run_radix_sort_neg_tests() {
    cout << "radix_sort_neg tests" << endl;

    const int tests_number = 5;
    const int max_length = 12;

    int data[tests_number][max_length] = {
        {170,-45,75,-90,802,24,-2,66},                
        {-10,7,-8,9,-1,5,-2,3},                 
        {1,-9,2,-8,3,-7,4,-6,5},                
        {-3,1,-4,1,-5,9,-2,6},                  
        {9,-9,8,-8,7,-7,6,-6,5}                
    };

    int sizes[tests_number] = {8,8,9,8,9};

    for (int t = 0; t < tests_number; ++t) {
        int a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        radix_sort_neg(a, sizes[t], 10);
        cout << "test " << t << ": " << (is_sorted_int(a,sizes[t]) ) << endl;
    }
}

// BUCKET SORT TESTS
void run_bucket_sort_tests() {
    cout << "bucket_sort tests" << endl;

    const int tests_number = 10;
    const int max_length = 12;
    float data[tests_number][max_length] = {
        {0.42f, 0.32f, 0.23f, 0.52f, 0.25f, 0.47f, 0.51f},                
        {0.1f, 0.7f, 0.8f, 0.9f, 0.2f, 0.5f, 0.3f},                 
        {0.01f, 0.09f, 0.02f, 0.08f, 0.03f, 0.07f, 0.04f, 0.06f, 0.05f},                
        {0.3f, 0.1f, 0.4f, 0.1f, 0.5f, 0.9f, 0.2f, 0.6f},                  
        {0.9f, 0.9f, 0.8f, 0.8f, 0.7f, 0.7f, 0.6f, 0.6f, 0.5f},                
        {0.4f, 0.3f, 0.2f, 0.7f, 0.8f, 0.9f, 0.2f, 0.3f, 0.4f, 0.5f},              
        {0.99f, 0.01f, 0.50f, 0.23f, 0.77f, 0.10f, 0.11f, 0.05f, 0.04f, 0.03f, 0.02f, 0.01f},    
        {0.15f, 0.14f, 0.13f, 0.12f, 0.11f, 0.10f, 0.09f, 0.08f, 0.07f, 0.06f},        
        {0.5f, 0.1f, 0.3f, 0.9f, 0.8f, 0.2f, 0.4f, 0.7f, 0.6f, 0.0f, 0.11f},           
        {0.42f, 0.17f, 0.08f, 0.23f, 0.99f, 0.01f, 0.00f, 0.04f, 0.03f, 0.55f, 0.30f, 0.18f}
    };

    int sizes[tests_number] = {7,7,9,8,9,10,12,10,11,12};

    for (int t = 0; t < tests_number; ++t) {
        float a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        bucket_sort(a, sizes[t]);
        cout << "test " << t << ": " << (is_sorted_float(a,sizes[t]) ) << endl;
    }
}

// BUCKET SORT FOR ALL TESTS

void run_bucket_sort_for_all_tests() {
    cout << "bucket_sort_for_all tests" << endl;

    const int tests_number = 10;
    const int max_length = 12;
    float data[tests_number][max_length] = {
        {42.0f, -32.5f, 23.1f, 52.3f, -25.4f, 47.6f, 51.2f},                
        {-10.1f, 70.2f, -8.3f, 9.4f, -1.5f, 5.6f, -2.7f, 3.8f},                 
        {1.0f, -9.1f, 2.2f, -8.3f, 3.4f, -7.5f, 4.6f, -6.7f, 5.8f},                
        {-3.3f, 1.1f, -4.4f, 1.5f, -5.6f, 9.7f, -2.8f, 6.9f},                  
        {9.9f, -9.8f, 8.7f, -8.6f, 7.5f, -7.4f, 6.3f, -6.2f, 5.1f},                
        {4.0f, -3.1f, 2.2f, 7.3f, -8.4f, 9.5f, -2.6f, 3.7f, -4.8f, 5.9f},              
        {99.9f, -1.1f, 50.5f, 23.3f, -77.7f, 10.0f, -11.2f, 5.4f, -4.6f, 3.8f, -2.0f, 1.2f},    
        {15.6f, -14.7f, 13.8f, -12.9f, 11.0f, -10.1f, 9.2f, -8.3f, 7.4f, -6.5f},        
        {5.5f, -1.6f, 3.7f, -9.8f, 8.9f, -2.0f, 4.1f, -7.2f, 6.3f, 0.4f, -11.5f},           
        {42.3f, -17.4f, 8.5f, -23.6f, 99.7f, -1.8f, 0.0f, -4.9f, 3.1f, 55.2f, -30.3f, 18.4f}
    };

    int sizes[tests_number] = {7,8,9,8,9,10,12,10,11,12};

    for (int t = 0; t < tests_number; ++t) {
        float a[max_length];
        for (int i = 0; i < sizes[t]; ++i) a[i] = data[t][i];

        bucket_sort_for_all(a, sizes[t]);
        cout << "test " << t << ": " << (is_sorted_float(a,sizes[t]) ) << endl;
    }
}

// INSERTION SORT TESTS
void run_insertion_sort_tests() {
    cout << "insertion_sort tests" << endl;

    const int tests_number = 5;
    const int max_length = 10;

    float data[tests_number][max_length] = {
        {0.42f, 0.32f, 0.23f, 0.52f, 0.25f},                
        {0.1f, 0.7f, 0.8f, 0.9f, 0.2f},                 
        {0.01f, 0.09f, 0.02f, 0.08f, 0.03f, 0.07f, 0.04f},                
        {0.3f, 0.1f, 0.4f, 0.1f, 0.5f},                  
        {0.9f, 0.9f, 0.8f, 0.8f, 0.7f}                
    };

    int sizes[tests_number] = {5,5,7,5,5};

    for (int t = 0; t < tests_number; ++t) {
        Node* head = nullptr;
        for (int i = 0; i < sizes[t]; ++i) {
            append(head, data[t][i]);
        }

        insertion_sort(head);

        // Check if sorted
        bool sorted = true;
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->value > current->next->value + 1e-6f) {
                sorted = false;
                break;
            }
            current = current->next;
        }

        cout << "test " << t << ": " << sorted << endl;
    }
}

#ifndef GENERATE_DATA
int main() {
    run_quick_sort_tests();
    run_quick_sort_2_divider_tests();
    run_radix_sort_tests();
    run_radix_sort_neg_tests();
    run_bucket_sort_tests();
    run_bucket_sort_for_all_tests();
    run_insertion_sort_tests();
    return 0;
}
#endif