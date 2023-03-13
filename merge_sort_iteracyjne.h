#ifndef AISD_MERGE_SORT_ITERACYJNE_H
#define AISD_MERGE_SORT_ITERACYJNE_H

#include "table_based_sort.h"

class IterMergeSort: public TableBasedSort{
public:
    IterMergeSort(int s, int* arr);
    int* getTable(){
        return this->table;
    }
private:
    void Sort();
};

#endif //AISD_MERGE_SORT_ITERACYJNE_H
