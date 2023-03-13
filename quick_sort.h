//
// Created by malik on 23.04.2022.
//

#ifndef AISD_QUICK_SORT_H
#define AISD_QUICK_SORT_H

#include "table_based_sort.h"


class QuickSort: public TableBasedSort{
public:
    QuickSort(int s, int *arr);

private:
    int start;
    int end;
    int pivot;
    void Sort(int start, int end);
    int partition(int start, int end);
    void swap(int a, int b);
};

#endif //AISD_QUICK_SORT_H
