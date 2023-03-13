#ifndef AISD_HEAP_SORT_H
#define AISD_HEAP_SORT_H

#include "table_based_sort.h"

class HeapSort: public TableBasedSort{
public:
    HeapSort(int s, int* arr);
private:
    void Sort();
    void heapify( int n, int i);
    void swap(int a, int b);
};

#endif //AISD_HEAP_SORT_H
