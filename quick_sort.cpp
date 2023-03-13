
#include "quick_sort.h"

QuickSort::QuickSort(int s, int *arr): TableBasedSort(s, arr) {
    this->name = "QuickSort";
    this->complex = "Best case: O(nlogn) Average case: O(nlogn) Worst case: O(n^2)";
    this->start = 0;
    this->end = s;

    std::clock_t begin;
    begin = std::clock();
    Sort(start, end);
    duration = ( std::clock() - begin ) / (double) CLOCKS_PER_SEC;
}

void QuickSort::Sort(int start, int end) {
    if (start >= end)
        return;
    int i = partition(start, end);
    Sort(i + 1, end);
    Sort(start, i - 1);
}
int QuickSort::partition(int start, int end){
    int i = start;
    int j = end +1;
    while(1){
        i++;
        while(table[i]<table[start]){
            i++;
            if (i==end)
                break;
        }
        j--;
        while(table[start]<table[j]){
            j--;
            if (j==start)
                break;
        }
        if (i>j)
            break;
        swap(i, j);
    }
    swap(start, j);
    return j;
}

void QuickSort::swap(int a, int b) {
    int pom = table[a];
    table[a] = table[b];
    table[b] = pom;
}

