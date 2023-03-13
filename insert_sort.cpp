
#include "insert_sort.h"

InsertSort::InsertSort(int s, int* arr): TableBasedSort(s, arr){
    this->name = "InsertSort";
    this->complex = "Best case: O(n) Average case: O(n^2) Worst case: O(n^2)";
    Sort();
}

void InsertSort::Sort() {
    std::clock_t start;
    start = std::clock();
    for (int i = 1; i<size; i++){
        int pom = table[i];
        int j = i-1;
        while(j>=0 && table[j] > pom){
            table[j+1] = table[j];
            j--;
        }
        table[j+1] = pom;
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
}

