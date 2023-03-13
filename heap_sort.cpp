//
// Created by malik on 23.04.2022.
//

#include "heap_sort.h"

HeapSort::HeapSort(int s, int* arr): TableBasedSort(s, arr){
    this->name = "HeapSort";
    this->complex =  "Best case: O(n) Average case: O(nlogn) Worst case: O(nlogn)";
    std::clock_t begin;
    begin = std::clock();
    Sort();
    this->duration = (std::clock() - begin) / (double) CLOCKS_PER_SEC;
}

void HeapSort::Sort() {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(0, i);
        heapify( i, 0);
    }
}

void HeapSort::heapify(int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && table[l] > table[largest])
        largest = l;

    if (r < n && table[r] > table[largest])
        largest = r;

    if (largest != i) {
        swap(i, largest);

        heapify (n, largest);
    }
}

void HeapSort::swap(int a, int b) {
    int pom = table[a];
    table[a] = table[b];
    table[b] = pom;
}