#include <iostream>
#include "insert_sort.h"
#include "quick_sort.h"
#include "bucket_sort.h"
#include "merge_sort.h"
#include "merge_sort_iteracyjne.h" //TODO
#include "heap_sort.h"
#include "simple_bucket_sort.h"

int main() {
    int tab[100000];
    for (int i = 0; i<100000; i++){
        tab[i] = rand() % 1000;
    }

    int test[100];
    for (int i = 0; i<100; i++){
        test[i] = rand() % 100;
    }

    InsertSort sorted(100000, tab);
    sorted.time();

    QuickSort sorted2(100000, tab);
    sorted2.time();

    SimpleBucketSort sorted3(100000, tab, 1000);
    sorted3.time();

    MergeSort sorted4(100000, tab);
    sorted4.time();

    HeapSort sorted5(100000, tab);
    sorted5.time();

    IterMergeSort sorted6(100000, tab);
    sorted6.time();

    BucketSort sorted7(100000, tab, 100, 1000);
    sorted7.time();

    return 0;
}
