#ifndef __RANDOMCOUNT_H
#define __RANDOMCOUNT_H

#include <vector>
#include <string>
#include <fstream>

class RandomCount{
    public:
    RandomCount();
    ~RandomCount();
    void PrintRandomCount();
    std::vector<int> HistoricalStatistic();
    void PrintLastRandom();

    private:
        std::vector<int> history_;
        void AddHistory(int number);
        int seed_;
        std::string filename_;
        std::ofstream file_;
};
#endif