#ifndef AISD_BUCKET_SORT_H
#define AISD_BUCKET_SORT_H

#include "table_based_sort.h"
#include <cmath>
#include <vector>
#include "merge_sort_iteracyjne.h"

class BucketSort: public TableBasedSort{
public:
    BucketSort(int s, int *arr, int k, int r);
    ~BucketSort();

private:
    int k;
    int rstart = 0;
    int rend = 0;
    int range;
    std::vector<int> pomvector;
    int *pomtable = new int[0];
    el** pocz;
    el** konce;
    el* lista;
    void Sort();
    int retable(el* pocz);
};

#endif //AISD_BUCKET_SORT_H
