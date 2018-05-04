#ifndef __RANDOMCOUNT_H
#define __RANDOMCOUNT_H

#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <mutex>
#include <condition_variable>

class RandomCount{
    public:
    RandomCount();
    ~RandomCount();
    void PrintRandomCount();
    std::vector<int> HistoricalStatistic();
    void StartWriter();
    

    private:
    void AddHistory(int number);
    void PushRandomNumber(int number);
    std::string PopRandomNumber();

    std::vector<int> history_;
    std::ofstream file_;
    std::mutex random_numbers_mutex_;
    std::queue<std::string> random_numbers_;
    std::condition_variable numbers_queue_condition_;
};
#endif