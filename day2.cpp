#include "day2.h"

#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

int checkline(std::string line, int ignore);

int d2p1(){
    int total = 0, num1, num2, inc,tempinc = 0,dif, safe;
    std::string line;

    while(std::getline(std::cin, line)){
        safe = 1;
        inc = 0;
        std::istringstream stream(line);
        stream >> num1;
        while (stream >> num2){
            if(num1 > num2){tempinc = -1;}
            else if(num1 < num2){tempinc = 1;}
            else{tempinc = 0;}
            if(inc == 0){inc = tempinc;}
            dif = std::abs(num1 - num2);
            if(dif > 3 || dif == 0 || tempinc != inc){
                safe = 0;
            }
            num1 = num2;
        }
        total += safe;
        std::cout << safe << "\n";
    }
    return total;
}

int d2p2(){
    int total = 0, num1, safe, i;
    std::string line;
    bool first = true;
    std::chrono::high_resolution_clock clock;
    auto t = clock.now();
    while(std::getline(std::cin, line)){
        if(first){
            t=clock.now();
            first = false;
        }
        safe = 0;
        i=0;
        std::istringstream stream(line);
        while (stream >> num1){
            safe = checkline(line,i);
            if(safe==1){
                break;
            }
            i++;
        }
        total += safe;
    }
    auto t2 = clock.now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2-t).count() << "\n";
    return total;
}

int checkline(std::string line, int ignore){
    int num1, num2, inc=0,tempinc = 0,dif, safe=1, i = 1;
    std::istringstream stream(line);
    if(ignore == 0){stream >> num1;}
    stream >> num1;
    while (stream >> num2){
        if(i == ignore){
            i++;
            continue;
        }
        if(num1 > num2){tempinc = -1;}
        else if(num1 < num2){tempinc = 1;}
        else{tempinc = 0;}
        if(inc == 0){inc = tempinc;}
        dif = std::abs(num1 - num2);
        if(dif > 3 || dif == 0 || tempinc != inc){
            safe = 0;
        }
        num1 = num2;
        i++;
    }
    return safe;
}