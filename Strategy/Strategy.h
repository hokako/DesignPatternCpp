#ifndef STRATEGY_H_
#define STRATEGY_H_

#include<vector>

class Sort
{
    public:
        virtual void sortVector(std::vector<int> &arr) = 0;
};

#endif //STRATEGY_H_