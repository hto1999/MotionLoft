#include "RandomCount.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <random>
#include <string.h>
#include <thread>
#include <condition_variable>

RandomCount::RandomCount(){
    srand(time(0));
}

RandomCount::~RandomCount(){
    if(file_.is_open())
        file_.close();
}


void RandomCount::PrintRandomCount(){
    std::thread threads[5];
    for(int i = 0; i < 5; i++){
        threads[i] = std::thread([this]{

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
        PushRandomNumber(result);
        });
    } 

    for(int i = 0; i < 5; i++)
        threads[i].join();
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


void RandomCount::StartWriter(){
    if(!file_.is_open())
        file_.open("random.txt");

    std::thread ([this]{
        while(true){
            file_ << PopRandomNumber() << std::endl;   
        }         
    }).detach();
    
}


void RandomCount::AddHistory(int number){
    history_.push_back(number);
    
    while(history_.size() > 100)
        history_.erase(history_.begin());
}

void RandomCount::PushRandomNumber(int number){
    std::unique_lock<std::mutex> lock(random_numbers_mutex_);
    time_t current_time;
    struct tm * timeinfo;

    time (&current_time);
    timeinfo = localtime (&current_time);
    char* time_c = asctime(timeinfo);
    time_c[strlen(time_c) -1] = 0;
    std::string s = time_c;
    s = s + "\t" + std::to_string(number);
    random_numbers_.push(s);

    numbers_queue_condition_.notify_all();
}

std::string RandomCount::PopRandomNumber(){
    std::string result;
    std::unique_lock<std::mutex> lock(random_numbers_mutex_);
    while(true){
        if(!random_numbers_.empty()){
            result = random_numbers_.front();
            random_numbers_.pop();
            break;
        }
        else{
            numbers_queue_condition_.wait(lock);
        }
    }

    return result;
}