#ifndef AISD_INSERT_SORT_H
#define AISD_INSERT_SORT_H

#include <iostream>
#include <ctime>
#include "table_based_sort.h"

class InsertSort: public TableBasedSort{
public:
    InsertSort(int s, int* arr);
    ~InsertSort(){}

private:
    void Sort();
};

#endif //AISD_INSERT_SORT_H
