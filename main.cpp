#include "RandomCount.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    RandomCount rc;

    rc.StartWriter();
    rc.PrintRandomCount();
    return 0;
}
