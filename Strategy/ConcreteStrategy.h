#ifndef CONCRETE_STRATEGY_H_
#define CONCRETE_STRATEGY_H_

#include <iostream>
#include <vector>
#include <cstring>
#include "Strategy.h"

template <class T>
void display(const std::string prefix, const std::vector<T> &arr)
{
    std::cout << prefix;
    for (auto i : arr)
        std::cout << ' ' << i;
    std::cout << std::endl;
}

template <class T>
class BubbleSort : public Sort
{
public:
    void sortVector(std::vector<T> &arr) override
    {
        int len = arr.size();
        display("Before BubbleSort:", arr);
        for (int i = 0; i < len - 1; i++)
        {
            bool flag = false;
            for (int j = 0; j < len - i - 1; j++)
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    flag = true;
                }
            if (!flag) // If there is no exchange in one round, it has been fully sorted
                break;
        }
        display("After BubbleSort:", arr);
    }
};

template <class T>
class SelectionSort : public Sort
{
public:
    void sortVector(std::vector<T> &arr) override
    {
        display("Before SelectionSort:", arr);
        int len = arr.size();
        for (int i = 0; i < len - 1; i++)
        {
            int minn = i;
            for (int j = i + 1; j < len; j++)
                if (arr[j] < arr[minn])
                    minn = j;
            std::swap(arr[i], arr[minn]);
        }
        display("After SelectionSort:", arr);
    }
};

template <class T>
class InsertionSort : public Sort
{
public:
    void sortVector(std::vector<T> &arr) override
    {
        display("Before InsertionSort:", arr);
        int len = arr.size();
        for (int i = 1; i < len; i++)
        {
            int insertValue = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > insertValue)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = insertValue;
        }
        display("After InsertionSort:", arr);
    }
};

// There are many other sort algorithms, but this is about design pattern, so i'm too lazy to write them down...

#endif