#include "RandomCount.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

void PrintRandomCount(){
    srand(time(NULL));
    int number = rand() % 100;    
    int result;

    if(number > 0 && number < 50){
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
    std::cout << result << std::endl;
}