//
// Created by malik on 23.04.2022.
//

#include "bucket_sort.h"

BucketSort::BucketSort(int s, int *arr, int k, int r): TableBasedSort(s, arr) {
    this->k = k;
    this->range = r/k;
    this->name = "BucketSort";
    this->complex = "Best case: O(n+k) Average case: O(n+k) Worst case: O(n^2)";

    std::clock_t begin;
    begin = std::clock();
    Sort();
    duration = ( std::clock() - begin ) / (double) CLOCKS_PER_SEC;
}

BucketSort::~BucketSort() {
        delete [] pocz;
        delete [] konce;
        delete [] pomtable;
        el *wsk;
        while(lista!= nullptr){
            wsk = lista;
            lista = lista->ws;
            delete wsk;
        }
    }

void BucketSort::Sort() {
    pocz = new el *[k];
    konce = new el *[k];

    el *wsk;

    for(int i = 0; i < k; i++)
        pocz[i] = nullptr;

    for (int i=0; i<size; i++){
        wsk = new el;
        wsk->w = table[i];
        wsk->ws = nullptr;
        if (!pocz[int(table[i]/range)]){
            pocz[int(table[i]/range)] = wsk;
            konce[int(table[i]/range)] = wsk;
        }
        else{
            konce[int(table[i]/range)]->ws = wsk;
            konce[int(table[i]/range)] = wsk;
        }
    }
    //SORTOWANIE KUBELKOW
    int i=0;
    int x = 0;
    for (; pocz[i]== nullptr && i<k; i++);
    for(; i<k; i++){
        int pomsize = retable(pocz[i]);
        IterMergeSort pom(pomsize, pomtable);
        int *parttable = pom.getTable();
        for (int j = 0; j<pomsize; j++){
            table[x] = parttable[j];
            x++;
        }
    }

}

int BucketSort::retable(el* pocz) {
    el *wsk = pocz;
    while(wsk!= nullptr ){
    pomvector.push_back(wsk->w);
    wsk = wsk->ws;
    }
    delete [] pomtable;
    int x = pomvector.size();
    pomtable = new int[x];
    for (int i =0; i<x; i++)
        pomtable[i] = pomvector[i];
    pomvector.clear();
    return x;
}




