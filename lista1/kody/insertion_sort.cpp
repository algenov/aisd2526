#include <iostream>
using namespace std;


int insertion_sort(int arr[], int n) {
    int number_of_operations = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            number_of_operations++;
            j--;

        }
        arr[j + 1] = key;
        number_of_operations++;
    }
    return number_of_operations;
}

int insertion_sort_pairs(int arr[], int n) {
    int number_of_operations = 0;
    for (int i = 0; i < n-1; i = i + 2) {
        int key_1 = arr[i];
        int key_2 = arr[i + 1];
        int j = i - 1;
        if (key_1 > key_2) {
            swap(key_1, key_2);
            number_of_operations++;
        }

        // na razie mamy dwa elementy, ktore chcemy do tej tablicy dodac posortowane

        //  możemy zrobić to, co robilismy dla jednego elementu najpierw dla mniejszego a potem dla wiekszego

        // ale chyba szybciej będzie najpierw wiekszy a juz potem mniejszy od tego samego miejsca
        while (j >= 0 && arr[j] > key_2) {
            arr[j + 2] = arr[j];
            number_of_operations++;
            j--;
        }

        arr[j + 2] = key_2;
        number_of_operations++;

        number_of_operations++; // porownanie w while
        while (j >= 0 && arr[j] > key_1) {
            arr[j + 1] = arr[j];
            number_of_operations++;
            j--;

        }
        arr[j + 1] = key_1;
        number_of_operations++;

    }
    // jesli jeszcze zostal jeden element do wstawienia
    if (n % 2 != 0) {
        int key = arr[n - 1];
        int j = n - 2;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            number_of_operations++;
            j--;
        }
        arr[j + 1] = key;
        number_of_operations++;
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