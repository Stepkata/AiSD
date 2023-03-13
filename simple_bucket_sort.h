//
// Created by malik on 30.04.2022.
//

#ifndef AISD_SIMPLE_BUCKET_SORT_H
#define AISD_SIMPLE_BUCKET_SORT_H

#include "table_based_sort.h"

class SimpleBucketSort: public TableBasedSort{
public:
    SimpleBucketSort(int s, int *arr, int k);

    ~SimpleBucketSort();

private:
    int k;
    el** pocz;
    el** konce;
    el* lista;
    void Sort();
    void retable();
};

#endif //AISD_SIMPLE_BUCKET_SORT_H
