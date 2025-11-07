#include <iostream>
#include <climits>
#include <random>
#include "sort_stats.h"
using namespace std;




SortStats insertion_sort(int arr[], int n) {
    SortStats number_of_operations;
    for (int i = 1; i < n; i++) {
        number_of_operations.comparison++;
        int key = arr[i];
        number_of_operations.assign++;
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            number_of_operations.comparison++;
            arr[j + 1] = arr[j];
            number_of_operations.assign++;
            j--;

        }
        arr[j + 1] = key;
        number_of_operations.assign++;
    }
    return number_of_operations;
}

SortStats insertion_sort_pairs(int arr[], int n) {
    SortStats number_of_operations;
    for (int i = 0; i < n-1; i = i + 2) {
        number_of_operations.comparison++;
        int key_1 = arr[i];
        number_of_operations.assign++;
        int key_2 = arr[i + 1];
        number_of_operations.assign++;
        int j = i - 1;
        if (key_1 > key_2) {
            number_of_operations.comparison++;
            swap(key_1, key_2);
            number_of_operations.assign++;
        }

        // na razie mamy dwa elementy, ktore chcemy do tej tablicy dodac posortowane

        //  możemy zrobić to, co robilismy dla jednego elementu najpierw dla mniejszego a potem dla wiekszego

        // ale chyba szybciej będzie najpierw wiekszy a juz potem mniejszy od tego samego miejsca
        while (j >= 0 && arr[j] > key_2) {
            number_of_operations.comparison++;
            arr[j + 2] = arr[j];
            number_of_operations.assign++;
            j--;
        }

        arr[j + 2] = key_2;
        number_of_operations.assign++;
        number_of_operations.comparison++; // porownanie w while'u ktore sie nie wykonalo
        while (j >= 0 && arr[j] > key_1) {
            number_of_operations.comparison++;
            arr[j + 1] = arr[j];
            number_of_operations.assign++;
            j--;

        }
        arr[j + 1] = key_1;
        number_of_operations.assign++;

    }
    // jesli jeszcze zostal jeden element do wstawienia
    if (n % 2 != 0) {
        number_of_operations.comparison++;
        int key = arr[n - 1];
        number_of_operations.assign++;
        int j = n - 2;


        while (j >= 0 && arr[j] > key) {
            number_of_operations.comparison++;
            arr[j + 1] = arr[j];
            number_of_operations.assign++;
            j--;
        }
        arr[j + 1] = key;
        number_of_operations.assign++;
    }
    return number_of_operations;
}
// {9, 5, 2, 7, 1, 3}  {5,9,2,7,1,3}  {2,5,7,9,1,3} {1,2,3,5,7,9}  to po prostu przyklad, nad ktorym razwazalem




// int main() {
//     int arr1[] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11, 15};
//     int arr2[] = {9, 5, 2, 7, 1, 3, 6, 10, 4, 8, 12, 11, 15};
//     // troche pretesctowalem, zawsze drugi sposob jest szybszy pod wzgledem liczby operacji
//     int n = sizeof(arr1) / sizeof(arr1[0]);

//     int number_of_operations_in_simple_sort = insertion_sort(arr1, n);
//     int number_of_operations_in_pair_sort = insertion_sort_pairs(arr2, n);

//     cout << "simple insertion sort: ";
//     for (int x = 0; x < n; x++) {
//         cout << arr1[x] << " ";
//     }
//     cout << "\n";
//     cout << "Number of operations in simple insertion sort: " << number_of_operations_in_simple_sort << "\n";

//     cout << "pair insertion sort: ";
//     for (int x = 0; x < n; x++) {
//         cout << arr1[x] << " ";
//     }
//     cout << "\n";
//     cout << "Number of operations in pair insertion sort: " << number_of_operations_in_pair_sort << "\n";

//     return 0;
// }

// int main(){
//     int tab[200000];
//     generate_list(200000, tab);
//     long long operations = insertion_sort_pairs(tab, 200000);
//     for (int i = 0; i < 200000; i=i+1){
//         cout << tab[i] << " ";
//     }
//     cout << "\n";
//     cout << operations << "\n";
// }