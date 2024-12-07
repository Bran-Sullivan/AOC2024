#include "day7.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <unordered_map>
#include <set>
#include <iterator>
#include <tuple>
#include <cmath>

long long unsigned int d7p1(){
    long long unsigned int total = 0;
    long long unsigned int goal = 0, num=0;
    std::string inp;
    std::regex pattern("(\\d+)");
    std::vector<std::vector<long long unsigned int>> lines;
    while(std::getline(std::cin,inp)){
        std::vector<long long unsigned int> currLine;
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator j = matches_begin; j != matches_end; ++j){
            std::smatch match = *j;
            currLine.push_back(stoull(match[0].str()));
        }
        lines.push_back(currLine);
    }
    for(size_t i = 0; i<lines.size(); i++){
        goal = lines[i][0];
        num = lines[i][1];
        for(size_t j = 2; j<lines[i].size(); j++){
            num *= lines[i][j];
        }
        if(num < goal){
            continue;
        }
        num = lines[i][1];
        for(size_t j = 2; j<lines[i].size(); j++){
            num += lines[i][j];
        }
        if(num > goal){
            continue;
        }
        long long unsigned int c = 1ULL << (lines[i].size() - 2);
        for(long long unsigned int k = 0; k<c; k++){
            num = lines[i][1];
            std::bitset<128> bs(k);
            for(size_t j = 2; j<lines[i].size(); j++){
                if(num>goal){
                    break;
                }
                if(bs[j-2]==0){
                    num*=lines[i][j];
                }
                if(bs[j-2]==1){
                    num+=lines[i][j];
                }
            }
            if(num==goal){
                total += goal;
                break;
            }
        }
    }
    return total;
}

int d7p2(){
    
}