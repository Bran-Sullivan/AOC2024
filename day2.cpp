#include "day2.h"

#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

}