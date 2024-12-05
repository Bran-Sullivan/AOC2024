#include "day5.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <unordered_map>
#include <set>
#include <iterator>

int d5p1(){
    int total = 0;
    std::string inp;
    std::regex pattern("(\\d{1,2})\\|(\\d{1,2})");
    std::unordered_map<int, std::set<int>> map;
    while(std::getline(std::cin, inp) && inp != ""){
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator i = matches_begin; i != matches_end; ++i){
            std::smatch match = *i;
            map[std::stoi(match[1].str())].insert(std::stoi(match[2].str())); //can check if any of the invalid ones have come before it. (indexed by second number)
        }
    }
    while(std::getline(std::cin, inp)){
        std::vector<int> numbers;
        std::set<int> prev;
        std::stringstream ss(inp);
        std::string token;
        bool invalid = false;
        while (std::getline(ss, token, ',')) {
            numbers.push_back(std::stoi(token));
        }
        for (int i = 0; i< numbers.size(); i++) {
            prev.insert(numbers[i]);
            if(invalid==true){
                break;
            }
            for (int elem : map[numbers[i]]) {
                if (prev.find(elem) != prev.end()) {
                    invalid = true;
                    break;
                }
            }
        }
        if(invalid == false){
            total+= numbers[numbers.size() / 2];
        }
    }
    return total;
}

int d5p2(){
    int total = 0;
    std::string inp;
    std::regex pattern("(\\d{1,2})\\|(\\d{1,2})");
    std::unordered_map<int, std::set<int>> map;
    while(std::getline(std::cin, inp) && inp != ""){
        auto matches_begin = std::sregex_iterator(inp.begin(), inp.end(), pattern);
        auto matches_end = std::sregex_iterator();
        for(std::sregex_iterator i = matches_begin; i != matches_end; ++i){
            std::smatch match = *i;
            map[std::stoi(match[1].str())].insert(std::stoi(match[2].str())); //can check if any of the invalid ones have come before it. (indexed by second number)
        }
    }
    std::vector<std::vector<int>> incorrect;
    while(std::getline(std::cin, inp)){
        std::vector<int> numbers;
        std::set<int> prev;
        std::stringstream ss(inp);
        std::string token;
        bool invalid = false;
        while (std::getline(ss, token, ',')) {
            numbers.push_back(std::stoi(token));
        }
        for (int i = 0; i< numbers.size(); i++) {
            prev.insert(numbers[i]);
            if(invalid==true){
                break;
            }
            for (int elem : map[numbers[i]]) {
                if (prev.find(elem) != prev.end()) {
                    invalid = true;
                    break;
                }
            }
        }
        if(invalid == true){
            incorrect.push_back(numbers);
        }
    }
    for (size_t i = 0; i< incorrect.size(); i++) {
        std::vector<int> sorted;
        std::set<int> nums;
        for (size_t j = 0; j< incorrect[i].size(); j++) {
            if(j==0){
                sorted.push_back(incorrect[i][0]);
                j++;
            }
            nums = map[incorrect[i][j]];
            for (int k = 0; k < sorted.size(); k++) {
                if(nums.find(sorted[k]) != nums.end()){
                    sorted.insert(sorted.begin() + k, incorrect[i][j]);
                    break;
                }
                else if(k==sorted.size()-1){
                    sorted.push_back(incorrect[i][j]);
                    break;
                }
            }
        }
        total += sorted[sorted.size() / 2];
    }
    return total;
}