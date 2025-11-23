#include "sorts.h"
#include "counters.h"
#include <climits>
#include <fstream>
#include <random>
#include <iostream>
#include <limits>
using namespace std;

static const int seed = 1;

int random_int(int min_val, int max_val) {
    static std::mt19937 rng(seed);  
    std::uniform_int_distribution<int> dist(min_val, max_val);
    return dist(rng);
}

float random_float(float min_val, float max_val) {
    static std::mt19937 rng(seed);  
    std::uniform_real_distribution<float> dist(min_val, max_val);
    return dist(rng);
}

void fill_random_int_array(int list[], int n, int min_val, int max_val) {
    for (int i = 0; i < n; i++) {
        list[i] = random_int(min_val, max_val);
    }
}

void fill_random_float_array(float list[], int n, float min_val, float max_val) {
    for (int i = 0; i < n; i++) {
        list[i] = random_float(min_val, max_val);
    }
}

#ifdef GENERATE_DATA
int main(){
    int first_length = 50000;
    int last_length = 2000000;
    int step = 50000;
    ofstream quick_sort_file("../sprawozdanie/quick_sort_data.txt");
    ofstream quick_sort_2_divider_file("../sprawozdanie/quick_sort_2_divider_data.txt");    
    ofstream radix_sort_2_file("../sprawozdanie/radix_sort_2_data.txt");
    ofstream radix_sort_10_file("../sprawozdanie/radix_sort_10_data.txt");
    ofstream radix_sort_16_file("../sprawozdanie/radix_sort_16_data.txt");
    ofstream bucket_sort_for_all_random_file("../sprawozdanie/bucket_sort_for_all_data.txt");
    ofstream bucket_sort_for_all_classic_file("../sprawozdanie/bucket_sort_for_all_classic_data.txt");

    
    for (int n = first_length; n <= last_length; n += step) {

        int* table = new int[n];
        fill_random_int_array(table, n, 0, INT_MAX);
        c.reset();
        quick_sort(table, 0, n-1);
        quick_sort_file << n << " " << c.comparisons << " " << c.assignments << endl;



        fill_random_int_array(table, n, 0, INT_MAX);
        c.reset();
        quick_sort_2_divider(table, 0, n-1);
        quick_sort_2_divider_file << n << " " << c.comparisons << " " << c.assignments << endl;



        fill_random_int_array(table, n, 0, INT_MAX);
        c.reset();
        radix_sort(table, n, 2);
        radix_sort_2_file << n << " " << c.comparisons << " " << c.assignments << endl;


        fill_random_int_array(table, n, 0, INT_MAX);
        c.reset();
        radix_sort(table, n, 10);
        radix_sort_10_file << n << " " << c.comparisons << " " << c.assignments << endl;


        fill_random_int_array(table, n, 0, INT_MAX);
        c.reset();
        radix_sort(table, n, 16);
        radix_sort_16_file << n << " " << c.comparisons << " " << c.assignments << endl;


        float* table_float = new float[n];
        fill_random_float_array(table_float, n, 0.0f, 100000.0f);
        c.reset();
        bucket_sort_for_all(table_float, n);
        bucket_sort_for_all_random_file << n << " " << c.comparisons << " " << c.assignments << endl;


        fill_random_float_array(table_float, n, 0.0f, 1.0f);
        c.reset();
        bucket_sort_for_all(table_float, n);        // we use bucket_sort_for_all instead of simple bucket_sort to sort [0,1) range to check if performance will be better on smaller numbers
        bucket_sort_for_all_classic_file << n << " " << c.comparisons << " " << c.assignments << endl;
        delete[] table;
        delete[] table_float;
    }
    
}
#endif