//
// Created by malik on 30.04.2022.
//

#include "simple_bucket_sort.h"

SimpleBucketSort::SimpleBucketSort(int s, int *arr, int k): TableBasedSort(s, arr){
    this->k = k;
    this->name = "SimpleBucketSort";
    this->complex = "Best case: O(n+k) Average case: O(n+k) Worst case: O(n^2)";

    std::clock_t begin;
    begin = std::clock();
    Sort();
    duration = ( std::clock() - begin ) / (double) CLOCKS_PER_SEC;
    retable();
}

SimpleBucketSort::~SimpleBucketSort(){
    delete [] pocz;
    delete [] konce;
    el *wsk;
    while(lista!= nullptr){
        wsk = lista;
        lista = lista->ws;
        delete wsk;
    }
}

void SimpleBucketSort::Sort() {
    pocz = new el *[k];
    konce = new el *[k];

    el *wsk;

    for(int i = 0; i < k; i++)
        pocz[i] = nullptr;

    for (int i=0; i<size; i++){
        wsk = new el;
        wsk->w = table[i];
        wsk->ws = nullptr;
        if (!pocz[table[i]]){
            pocz[table[i]] = wsk;
            konce[table[i]] = wsk;
        }
        else{
            konce[table[i]]->ws = wsk;
            konce[table[i]] = wsk;
        }
    }
    int i=0;
    for (; pocz[i]== nullptr && i<k; i++);
    lista = pocz[i];
    wsk = konce[i];
    i++;
    for(; i<k; i++){
        if (pocz[i]!= nullptr){
            wsk->ws = pocz[i];
            wsk=konce[i];
        }
    }
}

void SimpleBucketSort::retable() {
    el *wsk = lista;
    int i = 0;
    while(wsk!= nullptr ){
        this->table[i] = wsk->w;
        i++;
        wsk = wsk->ws;
    }
}


