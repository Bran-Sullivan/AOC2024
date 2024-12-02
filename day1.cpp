#include <day1.h>

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int d1p1(){
    int num1,num2,dist;
    std::vector<int> list1, list2;
    while (std::cin >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    }
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    for (size_t i = 0; i < list1.size(); ++i) {
        if(list1[i] >= list2[i]){
            dist += list1[i] - list2[i];
        }
        else{
            dist += list2[i] - list1[i];
        }
    }
    return dist;
}

int d1p2(){
    int num1,num2;
    int sim = 0;
    std::vector<int> list1, list2, list3;
    while (std::cin >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
        list3.push_back(0);
    }
    for (size_t i = 0; i < list1.size(); ++i) {
        for (size_t j = 0; j < list2.size(); ++j) {
            if(list2[j] == list1[i]){
                list3[i]++;
            }
        }
    }
    for (size_t i = 0; i < list1.size(); ++i) {
        std::cout << list1[i] << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < list3.size(); ++i) {
        std::cout << list3[i] << " ";
    }
    for (size_t i = 0; i < list1.size(); ++i) {
        sim += list1[i] * list3[i];
    }
    return sim;
}