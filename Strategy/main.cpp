#include<iostream>
#include<algorithm>
#include<random>
#include<vector>
#include"ConcreteStrategy.h"
#include"Context.h"
template<class T>
std::vector<T> arrayMaker(std::vector<T> &v)
{
        auto e=std::default_random_engine{};
        std::shuffle(std::begin(v),std::end(v),e);
        return v;
}

int main()
{
    std::vector<int> v={1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    ArraySort<int> ArraySorter;
    {
        BubbleSort<int>* BubbleSorter=new BubbleSort<int>();
        arrayMaker(v);
        ArraySorter.setSortStrategy(BubbleSorter);
        ArraySorter.sortVector(v);
        delete BubbleSorter;
    }
    {
        SelectionSort<int>* SelectionSorter=new SelectionSort<int>();
        arrayMaker(v);
        ArraySorter.setSortStrategy(SelectionSorter);
        ArraySorter.sortVector(v);
        delete SelectionSorter;
    }
    {
        InsertionSort<int>* InsertionSorter=new InsertionSort<int>();
        arrayMaker(v);
        ArraySorter.setSortStrategy(InsertionSorter);
        ArraySorter.sortVector(v);
        delete InsertionSorter;
    }
    return 0;
}