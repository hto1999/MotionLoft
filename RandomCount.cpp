#include "RandomCount.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <random>

RandomCount::RandomCount(){
    srand(time(0));
}

void RandomCount::PrintRandomCount(){
    int number = rand() % 100;    
    int result;
 
    if(number >= 0 && number < 50){
        result = 1;
    }
    else if(number < 75){
        result = 2;
    }
    else if( number < 90){
        result = 3;
    }
    else if( number < 95){
        result = 4;
    }
    else {
        result = 5;
    }
    AddHistory(result);
 
    std::cout << result << std::endl;
}

std::vector<int> RandomCount::HistoricalStatistic(){
    std::vector<int> results(5,0);
    int count = 0;
    for(int number : history_){
        results[number]++;
        count++;
    }
    
    for(int i = 0; i < results.size(); i++){
        results[i] = (results[i] * 100)/count;
    }

    return results;
}

void RandomCount::AddHistory(int number){
    history_.push_back(number);
    while(history_.size() > 100)
        history_.erase(history_.begin());
}