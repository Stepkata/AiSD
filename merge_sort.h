#ifndef AISD_MERGE_SORT_H
#define AISD_MERGE_SORT_H

#include "table_based_sort.h"

class MergeSort: public TableBasedSort{
public:
    MergeSort(int s, int* arr);
private:
    void Sort(int lower, int upper);
    void Merge(int lower, int middle, int upper);
};

#endif //AISD_MERGE_SORT_H
