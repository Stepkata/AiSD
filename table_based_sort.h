#ifndef AISD_TABLE_BASED_SORT_H
#define AISD_TABLE_BASED_SORT_H
#include <iostream>
#include <ctime>

struct el{
    int w;
    struct el* ws;
};

struct elt{
    int klucz;
    int w;
    int nast;
};


class TableBasedSort{
public:
    TableBasedSort(int s, int* arr){
        this->size = s;
        this->table = arr;
    }
    void print();

    double Duration() const{
        return this->duration;
    }

    void time(){
        std::cout.precision(3);
        std::cout<<"Czas sortowania "<< this->name<<": " <<std::fixed << this->duration<<"\n";
    }

    int* tab(){
        return this->table;
    }

    void complexity(){
        std::cout<<this->complex<<std::endl;
    }

    ~TableBasedSort()=default;

protected:
    int size;
    int *table;
    long double duration = 0;
    std::string name{};
    std::string complex{};
};

#endif //AISD_TABLE_BASED_SORT_H
