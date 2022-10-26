#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <vector>
#include"Strategy.h"

template <class T>
class ArraySort
{
private:
    Sort *sort;

public:
    void sortVector(std::vector<T> &arr)
    {
        this->sort->sortVector(arr);
    }
    void setSortStrategy(Sort *sort)
    {
        this->sort = sort;
    }
};

#endif