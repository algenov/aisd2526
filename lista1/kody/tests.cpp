#include <iostream>
#include "insertion_sort.cpp"
#include "merge_sort.cpp"
#include "heap_sort.cpp"
#include "merge_sort_3.cpp"
#include "heap_sort_3.cpp"
#include <fstream>
using namespace std;

bool compareArrays(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void generate_list(int number_of_el, int tab[], int max_value){
    srand(10); // ustawiam tu 10 zeby potem mozna bylo sprawzic 
    for (int i = 0; i < number_of_el; i++){
        tab[i] = rand() % max_value;
        // cout << tab[i] << " ";
    }
    // cout << "\n";
}

void operations_number_insertion_sort(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_insertion.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = insertion_sort(tab, i);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}

void operations_number_insertion_sort_pairs(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_insertion_pairs.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = insertion_sort_pairs(tab, i);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}

void operations_number_merge_sort(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_merge.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = merge_sort(tab, 0, i - 1, 0);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}

void operations_number_merge_sort_3(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_merge_3.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = merge_sort_3(tab, 0, i - 1, 0);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}

void operations_number_heap_sort(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_heap.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = heap_sort(tab, i);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}

void operations_number_heap_sort_3(int max_number, int tab[], int min_number){
    int operations;
    std::ofstream out("../sprawozdanie/results_for_heap_3.txt");
    std::streambuf* old_buf = std::cout.rdbuf(out.rdbuf());
    for (size_t i = min_number; i < max_number; i++)
    {
        generate_list(i, tab, i);
        operations = heap_sort_3(tab, i);
        cout << operations << " ";
    }
    std::cout.rdbuf(old_buf);
}


int main(){
    int min_number = 10;
    int max_number = 2000;
    int tab[max_number];

    int size_1 = 10;
    int tab_1_for_insertion_sort[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_for_insertion_sort_pairs[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_for_merge_sort[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_for_merge_sort_3[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_for_heap_sort[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_for_heap_sort_3[size_1] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10};
    int tab_1_sorted[size_1] = {1,3,5,6,7,9,10,11,12,13};

    int size_2 = 16;
    int tab_2_for_insertion_sort[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_for_insertion_sort_pairs[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_for_merge_sort[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_for_merge_sort_3[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_for_heap_sort[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_for_heap_sort_3[size_2] = {38, 40, 43, 3, 9, 1, 100, 25, 76, 88, 55, 12, 13, 14, 15, 16};
    int tab_2_sorted[size_2] = {1,3,9,12,13,14,15,16,25,38,40,43,55,76,88,100};

    int size_3 = 20;
    int tab_3_for_insertion_sort[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_for_insertion_sort_pairs[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_for_merge_sort[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_for_merge_sort_3[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_for_heap_sort[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_for_heap_sort_3[size_3] = {34, 78, 23, 32, 5, 62, 32, 2, 45, 89, 90, 11, 27, 54, 31, 19, 88, 76, 15, 3};
    int tab_3_sorted[size_3] = {2,3,5,11,15,19,23,27,31,32,32,34,45,54,62,76,78,88,89,90};

    int size_4 = 12;
    int tab_4_for_insertion_sort[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_for_insertion_sort_pairs[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_for_merge_sort[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_for_merge_sort_3[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_for_heap_sort[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_for_heap_sort_3[size_4] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11};
    int tab_4_sorted[size_4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int size_5 = 8;
    int tab_5_for_insertion_sort[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_for_insertion_sort_pairs[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_for_merge_sort[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_for_merge_sort_3[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_for_heap_sort[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_for_heap_sort_3[size_5] = {22, 11, 99, 88, 9, 7, 42, 1};
    int tab_5_sorted[size_5] = {1,7,9,11,22,42,88,99};

    int operations_1_insertion_sort = insertion_sort(tab_1_for_insertion_sort, size_1);
    int operations_1_insertion_sort_pairs = insertion_sort_pairs(tab_1_for_insertion_sort_pairs, size_1);
    int operations_1_merge_sort = merge_sort(tab_1_for_merge_sort, 0, size_1 - 1, 0);
    int operations_1_merge_sort_3 = merge_sort_3(tab_1_for_merge_sort_3, 0, size_1 - 1, 0);
    int operations_1_heap_sort = heap_sort(tab_1_for_heap_sort, size_1);
    int operations_1_heap_sort_3 = heap_sort(tab_1_for_heap_sort_3, size_1);


    cout << "size_1: " << size_1 << "\n";
    if (compareArrays(tab_1_for_insertion_sort, tab_1_sorted, size_1)) {
        cout << "Insertion Sort 1 passed with " << operations_1_insertion_sort << " operations.\n";
    } else {
        cout << "Insertion Sort 1 failed.\n";
    }
    if (compareArrays(tab_1_for_insertion_sort_pairs, tab_1_sorted, size_1)) {
        cout << "Insertion Sort Pairs 1 passed with " << operations_1_insertion_sort_pairs << " operations.\n";
    } else {
        cout << "Insertion Sort Pairs 1 failed.\n";
    }
    if (compareArrays(tab_1_for_merge_sort, tab_1_sorted, size_1)) {
        cout << "Merge Sort 1 passed with " << operations_1_merge_sort << " operations.\n";
    } else {
        cout << "Merge Sort 1 failed.\n";
    }
    if (compareArrays(tab_1_for_merge_sort_3, tab_1_sorted, size_1)) {
        cout << "Merge Sort_3 1 passed with " << operations_1_merge_sort_3 << " operations.\n";
    } else {
        cout << "Merge Sort_3 1 failed.\n";
    }
    if (compareArrays(tab_1_for_heap_sort, tab_1_sorted, size_1)) {
        cout << "Heap Sort 1 passed with " << operations_1_heap_sort << " operations.\n";
    } else {
        cout << "Heap Sort 1 failed.\n";
    }
    if (compareArrays(tab_1_for_heap_sort_3, tab_1_sorted, size_1)) {
        cout << "Heap Sort_3 1 passed with " << operations_1_heap_sort_3 << " operations.\n";
    } else {
        cout << "Heap Sort_3 1 failed.\n";
    }
    
    cout << "\n";

    int operations_2_insertion_sort = insertion_sort(tab_2_for_insertion_sort, size_2);
    int operations_2_insertion_sort_pairs = insertion_sort_pairs(tab_2_for_insertion_sort_pairs, size_2);
    int operations_2_merge_sort = merge_sort(tab_2_for_merge_sort, 0, size_2 - 1, 0);
    int operations_2_merge_sort_3 = merge_sort_3(tab_2_for_merge_sort_3, 0, size_2 - 1, 0);
    int operations_2_heap_sort = heap_sort(tab_2_for_heap_sort, size_2);
    int operations_2_heap_sort_3 = heap_sort(tab_2_for_heap_sort_3, size_2);


    cout << "size_2: " << size_2 << "\n";
    if (compareArrays(tab_2_for_insertion_sort, tab_2_sorted, size_2)) {
        cout << "Insertion Sort 2 passed with " << operations_2_insertion_sort << " operations.\n";
    } else {
        cout << "Insertion Sort 2 failed.\n";
    }
    if (compareArrays(tab_2_for_insertion_sort_pairs, tab_2_sorted, size_2)) {
        cout << "Insertion Sort Pairs 2 passed with " << operations_2_insertion_sort_pairs << " operations.\n";
    } else {
        cout << "Insertion Sort Pairs 2 failed.\n";
    }
    if (compareArrays(tab_2_for_merge_sort, tab_2_sorted, size_2)) {
        cout << "Merge Sort 2 passed with " << operations_2_merge_sort << " operations.\n";
    } else {
        cout << "Merge Sort 2 failed.\n";
    }
    if (compareArrays(tab_2_for_merge_sort_3, tab_2_sorted, size_2)) {
        cout << "Merge Sort_3 2 passed with " << operations_2_merge_sort_3 << " operations.\n";
    } else {
        cout << "Merge Sort_3 2 failed.\n";
    }
    if (compareArrays(tab_2_for_heap_sort, tab_2_sorted, size_2)) {
        cout << "Heap Sort 2 passed with " << operations_2_heap_sort << " operations.\n";
    } else {
        cout << "Heap Sort 2 failed.\n";
    }
    if (compareArrays(tab_2_for_heap_sort_3, tab_2_sorted, size_2)) {
        cout << "Heap Sort_3 2 passed with " << operations_2_heap_sort_3 << " operations.\n";
    } else {
        cout << "Heap Sort_3 2 failed.\n";
    }

    cout << "\n";

    int operations_3_insertion_sort = insertion_sort(tab_3_for_insertion_sort, size_3);
    int operations_3_insertion_sort_pairs = insertion_sort_pairs(tab_3_for_insertion_sort_pairs, size_3);
    int operations_3_merge_sort = merge_sort(tab_3_for_merge_sort, 0, size_3 - 1, 0);
    int operations_3_merge_sort_3 = merge_sort_3(tab_3_for_merge_sort_3, 0, size_3 - 1, 0);
    int operations_3_heap_sort = heap_sort(tab_3_for_heap_sort, size_3);
    int operations_3_heap_sort_3 = heap_sort(tab_3_for_heap_sort_3, size_3);


    cout << "size_3: " << size_3 << "\n";
    if (compareArrays(tab_3_for_insertion_sort, tab_3_sorted, size_3)) {
        cout << "Insertion Sort 3 passed with " << operations_3_insertion_sort << " operations.\n";
    } else {
        cout << "Insertion Sort 3 failed.\n";
    }
    if (compareArrays(tab_3_for_insertion_sort_pairs, tab_3_sorted, size_3)) {
        cout << "Insertion Sort Pairs 3 passed with " << operations_3_insertion_sort_pairs << " operations.\n";
    } else {
        cout << "Insertion Sort Pairs 3 failed.\n";
    }
    if (compareArrays(tab_3_for_merge_sort, tab_3_sorted, size_3)) {
        cout << "Merge Sort 3 passed with " << operations_3_merge_sort << " operations.\n";
    } else {
        cout << "Merge Sort 3 failed.\n";
    }
    if (compareArrays(tab_3_for_merge_sort_3, tab_3_sorted, size_3)) {
        cout << "Merge Sort_3 3 passed with " << operations_3_merge_sort_3 << " operations.\n";
    } else {
        cout << "Merge Sort_3 3 failed.\n";
    }
    if (compareArrays(tab_3_for_heap_sort, tab_3_sorted, size_3)) {
        cout << "Heap Sort 3 passed with " << operations_3_heap_sort << " operations.\n";
    } else {
        cout << "Heap Sort 3 failed.\n";
    }
    if (compareArrays(tab_3_for_heap_sort_3, tab_3_sorted, size_3)) {
        cout << "Heap Sort_3 3 passed with " << operations_3_heap_sort_3 << " operations.\n";
    } else {
        cout << "Heap Sort_3 3 failed.\n";
    }

    cout << "\n";

    int operations_4_insertion_sort = insertion_sort(tab_4_for_insertion_sort, size_4);
    int operations_4_insertion_sort_pairs = insertion_sort_pairs(tab_4_for_insertion_sort_pairs, size_4);
    int operations_4_merge_sort = merge_sort(tab_4_for_merge_sort, 0, size_4 - 1, 0);
    int operations_4_merge_sort_3 = merge_sort_3(tab_4_for_merge_sort_3, 0, size_4 - 1, 0);
    int operations_4_heap_sort = heap_sort(tab_4_for_heap_sort, size_4);
    int operations_4_heap_sort_3 = heap_sort(tab_4_for_heap_sort_3, size_4);


    cout << "size_4: " << size_4 << "\n";
    if (compareArrays(tab_4_for_insertion_sort, tab_4_sorted, size_4)) {
        cout << "Insertion Sort 4 passed with " << operations_4_insertion_sort << " operations.\n";
    } else {
        cout << "Insertion Sort 4 failed.\n";
    }
    if (compareArrays(tab_4_for_insertion_sort_pairs, tab_4_sorted, size_4)) {
        cout << "Insertion Sort Pairs 4 passed with " << operations_4_insertion_sort_pairs << " operations.\n";
    } else {
        cout << "Insertion Sort Pairs 4 failed.\n";
    }
    if (compareArrays(tab_4_for_merge_sort, tab_4_sorted, size_4)) {
        cout << "Merge Sort 4 passed with " << operations_4_merge_sort << " operations.\n";
    } else {
        cout << "Merge Sort 4 failed.\n";
    }
    if (compareArrays(tab_4_for_merge_sort_3, tab_4_sorted, size_4)) {
        cout << "Merge Sort_3 4 passed with " << operations_4_merge_sort_3 << " operations.\n";
    } else {
        cout << "Merge Sort_3 4 failed.\n";
    }
    if (compareArrays(tab_4_for_heap_sort, tab_4_sorted, size_4)) {
        cout << "Heap Sort 4 passed with " << operations_4_heap_sort << " operations.\n";
    } else {
        cout << "Heap Sort 4 failed.\n";
    }
    if (compareArrays(tab_4_for_heap_sort_3, tab_4_sorted, size_4)) {
        cout << "Heap Sort_3 4 passed with " << operations_4_heap_sort_3 << " operations.\n";
    } else {
        cout << "Heap Sort_3 4 failed.\n";
    }

    cout << "\n";

    int operations_5_insertion_sort = insertion_sort(tab_5_for_insertion_sort, size_5);
    int operations_5_insertion_sort_pairs = insertion_sort_pairs(tab_5_for_insertion_sort_pairs, size_5);
    int operations_5_merge_sort = merge_sort(tab_5_for_merge_sort, 0, size_5 - 1, 0);
    int operations_5_merge_sort_3 = merge_sort_3(tab_5_for_merge_sort_3, 0, size_5 - 1, 0);
    int operations_5_heap_sort = heap_sort(tab_5_for_heap_sort, size_5);
    int operations_5_heap_sort_3 = heap_sort(tab_5_for_heap_sort_3, size_5);


    cout << "size_5: " << size_5 << "\n";
    if (compareArrays(tab_5_for_insertion_sort, tab_5_sorted, size_5)) {
        cout << "Insertion Sort 5 passed with " << operations_5_insertion_sort << " operations.\n";
    } else {
        cout << "Insertion Sort 5 failed.\n";
    }
    if (compareArrays(tab_5_for_insertion_sort_pairs, tab_5_sorted, size_5)) {
        cout << "Insertion Sort Pairs 5 passed with " << operations_5_insertion_sort_pairs << " operations.\n";
    } else {
        cout << "Insertion Sort Pairs 5 failed.\n";
    }
    if (compareArrays(tab_5_for_merge_sort, tab_5_sorted, size_5)) {
        cout << "Merge Sort 5 passed with " << operations_5_merge_sort << " operations.\n";
    } else {
        cout << "Merge Sort 5 failed.\n";
    }
    if (compareArrays(tab_5_for_merge_sort_3, tab_5_sorted, size_5)) {
        cout << "Merge Sort_3 5 passed with " << operations_5_merge_sort_3 << " operations.\n";
    } else {
        cout << "Merge Sort_3 5 failed.\n";
    }
    if (compareArrays(tab_5_for_heap_sort, tab_5_sorted, size_5)) {
        cout << "Heap Sort 5 passed with " << operations_5_heap_sort << " operations.\n";
    } else {
        cout << "Heap Sort 5 failed.\n";
    }
    if (compareArrays(tab_5_for_heap_sort_3, tab_5_sorted, size_5)) {
        cout << "Heap Sort_3 5 passed with " << operations_5_heap_sort_3 << " operations.\n";
    } else {
        cout << "Heap Sort_3 5 failed.\n";
    }


    // tu bedzie czesc generujaca losowe tablice i szukajaca liczbe operacji

    cout << "\n" << "operatoins number for insertion sort for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_insertion_sort(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_insertion.txt\n";
    cout << "\n";

    cout << "\n" << "operatoins number for insertion sort pairs for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_insertion_sort_pairs(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_insertion_pairs.txt\n";
    cout << "\n";

    cout << "\n" << "operatoins number for merge sort for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_merge_sort(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_merge.txt\n";
    cout << "\n";

    cout << "\n" << "operatoins number for merge sort 3 for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_merge_sort_3(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_merge_3.txt\n";
    cout << "\n";

    cout << "\n" << "operatoins number for heap sort for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_heap_sort(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_heap.txt\n";
    cout << "\n";
    
    cout << "\n" << "operatoins number for heap sort 3 for lengths " << min_number << " to " << max_number << ":\n";
    operations_number_heap_sort_3(max_number, tab, min_number);
    cout << "can be found in ../sprawozdanie/results_for_heap_3.txt\n";
    

    return 0;
}