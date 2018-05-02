#include "RandomCount.h"
#include <iostream>

int main(int argc, char* argv[]){
    RandomCount rc;
    for(int i = 0; i < 80; i++)
        rc.PrintRandomCount();
    
    std::vector<int> statistic = rc.HistoricalStatistic();

    for( auto result : statistic)
        std::cout << result << std::endl;

    rc.PrintLastRandom();
    return 0;
}
