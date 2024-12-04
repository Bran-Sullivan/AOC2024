#include "day3.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

int d3p1(){
    int total = 0;
    std::string inp;
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)|do()|don't()");
    std::string x;
    while(std::getline(std::cin, inp)){
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator i = matches_begin; i != matches_end; ++i){
            std::smatch match = *i;
            total += std::stoi(match[1].str()) * std::stoi(match[2].str());
        }
    }
    return total;
}

int d3p2(){
    int total = 0;
    bool active = true;
    std::string inp;
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");
    std::string x;
    while(std::getline(std::cin, inp)){
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator i = matches_begin; i != matches_end; ++i){
            std::smatch match = *i;
            if(match[0].str() == "do()"){
                active = true;
            }
            else if(match[0].str() == "don't()"){
                active = false;
            }
            else if(active && match[1].matched && match[2].matched){
                total += std::stoi(match[1].str()) * std::stoi(match[2].str());
            }
        }
    }
    return total;
}