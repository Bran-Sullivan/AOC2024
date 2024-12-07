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

int d7p1(){
    int total = 0;
    int goal = 0, num=0;
    std::string inp;
    std::regex pattern("(\\d+)");
    std::vector<std::vector<int>> lines;
    while(std::getline(std::cin,inp)){
        std::vector<int> currLine;
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator j = matches_begin; j != matches_end; ++j){
            std::smatch match = *j;
            currLine.push_back(stoi(match[0].str()));
        }
        lines.push_back(currLine);
    }
    for(size_t i = 0; i<lines.size(); i++){
        std::cout << "testing line:" << i << "\n";
        goal = lines[i][0];
        num = 1;
        for(size_t j = 1; j<lines[i].size(); j++){
            num *= lines[i][j];
        }
        if(num < goal){
            std::cout << "impossible goal too big" << "\n";
            continue;
        }
        num=0;
        for(size_t j = 1; j<lines[i].size(); j++){
            num += lines[i][j];
        }
        if(num > goal){
            std::cout << "impossible goal too small" << "\n";
            continue;
        }
        int c = 1 << (lines[i].size() - 2);
        std::bitset<64> bs1(c);
        for(int k = c; k>=0; k--){
            num = 0;
            std::bitset<64> bs2(k);
            if(bs2[0]==0){
                num=1;
            }
            for(size_t j = 1; j<lines[i].size(); j++){
                if(bs2[j-1]==0){
                    num*=lines[i][j];
                }
                else{
                    num+=lines[i][j];
                }
            }
            std::cout << num << "\n";
            if(num==goal){
                std::cout << "goal reachable" << "\n";
                total += goal;
                break;
            }
        }
    }
    return total;
}

int d7p2(){
    
}