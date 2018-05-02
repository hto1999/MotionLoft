#ifndef __RANDOMCOUNT_H
#define __RANDOMCOUNT_H

#include <vector>

class RandomCount{
    public:
    RandomCount();
    void PrintRandomCount();
    std::vector<int> HistoricalStatistic();

    private:
        std::vector<int> history_;
        void AddHistory(int number);
        int seed_;
};
#endif