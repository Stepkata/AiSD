//
// Created by malik on 23.04.2022.
//

#include "merge_sort.h"

MergeSort::MergeSort(int s, int* arr): TableBasedSort(s, arr){
    this->name = "MergeSort";
    this->complex = "Best case: O(nlogn) Average case: O(nlogn) Worst case: O(nlogn)";
    std::clock_t begin;
    begin = std::clock();
    Sort(0, s);
    duration = (std::clock() - begin) / (double ) CLOCKS_PER_SEC;
}

void MergeSort::Sort(int lower, int upper) {
    if (lower >= upper)
        return;
    Sort(lower, (lower+upper)/2);
    Sort(((lower+upper)/2)+1, upper);
    Merge(lower, (lower+upper)/2, upper);
}

void MergeSort::Merge(int low, int mid, int upper) {
    {
        int i, j, k, c[size+1];
        i = low;
        k = low;
        j = mid + 1;
        while (i <= mid && j <= upper) {
            if (table[i] < table[j]) {
                c[k] = table[i];
                k++;
                i++;
            } else {
                c[k] = table[j];
                k++;
                j++;
            }
        }
        while (i <= mid) {
            c[k] = table[i];
            k++;
            i++;
        }
        while (j <= upper) {
            c[k] = table[j];
            k++;
            j++;
        }
        for (i = low; i < k; i++) {
            table[i] = c[i];
        }
    }
}