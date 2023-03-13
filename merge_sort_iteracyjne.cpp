//
// Created by malik on 23.04.2022.
//

#include "merge_sort_iteracyjne.h"

IterMergeSort::IterMergeSort(int s, int* arr): TableBasedSort(s, arr){
    this->name = "IterMergeSort";
    this->complex = "Best case: O(nlogn) Average case: O(nlogn) Worst case: O(nlogn)";
    std::clock_t begin;
    begin = std::clock();
    Sort();
    this->duration = (std::clock() - begin) / (double) CLOCKS_PER_SEC;
}

void IterMergeSort::Sort() {
    int pomtab[size];
    for (int len=1; len<size; len*=2){
        for (int pocz = 0; pocz+len<size; pocz += 2*len){
            int maxi = pocz + len;
            int maxj = maxi + len;
            if (maxj > size)
                maxj = size;
            int i = pocz;
            int j = maxi;
            int k = pocz;
            while (i < maxi && j < maxj){
                if (table[i] <= table[j]){
                    pomtab[k] = table[i];
                    i++;
                }
                else {
                    pomtab[k] = table[j];
                    j++;
                }
                k++;
            }
            while (i < maxi){
                pomtab[k] = table[i];
                k++;
                i++;
            }
            while (j < maxj){
                pomtab[k] = table[j];
                k++;
                j++;
            }
            for (k = pocz; k<maxj; k++)
                table[k] = pomtab[k];
        }
    }
}