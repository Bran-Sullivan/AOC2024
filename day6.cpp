#include "day6.h"

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

int d6p1(){
    int total = 0;
    std::vector<int> guard (2,0); //couldn't figure out tuples
    std::vector<int> nextpos (2,0);
    std::vector<std::vector <int>> points;
    std::vector<std::string> board;
    int dir = 4;
    std::string inp;
    while(std::getline(std::cin, inp)){
        board.push_back(inp);
        for(int i = 0; i < inp.length(); i++){
            if(inp[i] == '^'){
                guard[0] = i;
                guard[1] =board.size()-1;
                std::cout << "guard: " << guard[0] << "," << guard[1] << "\n";
                nextpos[0] = i;
                nextpos[1] = board.size()-2;
                std::cout << "next: " << nextpos[0] << "," << nextpos[1] << "\n";
                points.push_back({nextpos[0],nextpos[1]});
                total++;
                board[guard[1]][guard[0]] = 'X';
            }
        }
    }
    while(nextpos[0] >= 0 && nextpos[0] <= inp.length() && nextpos[1] >= 0 && nextpos[1] <= board.size()-1){
        if(board[nextpos[1]][nextpos[0]] == '#'){
            switch(dir%4){
            case 0: nextpos[1]++; break;
            case 1: nextpos[0]--; break;
            case 2: nextpos[1]--; break;
            case 3: nextpos[0]++; break;
        }
            dir++;
        }
        else{
            if(board[nextpos[1]][nextpos[0]] != 'X'){
                points.push_back({nextpos[0],nextpos[1]});
                total++;
            }
            board[nextpos[1]][nextpos[0]] = 'X';
        }
        switch(dir%4){
            case 0: nextpos[1]--; break;
            case 1: nextpos[0]++; break;
            case 2: nextpos[1]++; break;
            case 3: nextpos[0]--; break;
        }
        std::cout << nextpos[1] << nextpos[0] << "\n";
    }
    return total;
}

int d6p2(){ //takes 28 seconds...
    int total = 0;
    std::vector<int> guard (2,0); //couldn't figure out tuples
    std::vector<int> nextpos (2,0);
    std::vector<std::vector <int>> points;
    std::vector<std::string> board;
    int dir = 4;
    int startx = 0;
    int starty = 0;
    std::string inp;
    while(std::getline(std::cin, inp)){
        board.push_back(inp);
        for(int i = 0; i < inp.length(); i++){
            if(inp[i] == '^'){
                guard[0] = i;
                guard[1] =board.size()-1;
                std::cout << "guard: " << guard[0] << "," << guard[1] << "\n";
                nextpos[0] = i;
                startx = i;
                nextpos[1] = board.size()-2;
                starty = board.size()-2;
                std::cout << "next: " << nextpos[0] << "," << nextpos[1] << "\n";
                points.push_back({nextpos[0],nextpos[1],dir});
                board[guard[1]][guard[0]] = 'X';
            }
        }
    }
    while(nextpos[0] >= 0 && nextpos[0] <= inp.length() && nextpos[1] >= 0 && nextpos[1] <= board.size()-1){
        if(board[nextpos[1]][nextpos[0]] == '#'){
            switch(dir%4){
            case 0: nextpos[1]++; break;
            case 1: nextpos[0]--; break;
            case 2: nextpos[1]--; break;
            case 3: nextpos[0]++; break;
        }
            dir++;
        }
        else{
            if(board[nextpos[1]][nextpos[0]] != 'X'){
                points.push_back({nextpos[0],nextpos[1],dir%4});
            }
            board[nextpos[1]][nextpos[0]] = 'X';
        }
        switch(dir%4){
            case 0: nextpos[1]--; break;
            case 1: nextpos[0]++; break;
            case 2: nextpos[1]++; break;
            case 3: nextpos[0]--; break;
        }
    }
    for(std::vector<int>point: points){
        dir = 4;
        std::vector<std::vector <int>> points2;
        nextpos[0] = startx;
        nextpos[1] = starty;
        board[point[1]][point[0]] = '#';
        while(nextpos[0] >= 0 && nextpos[0] <= inp.length() && nextpos[1] >= 0 && nextpos[1] <= board.size()-1){
        if(board[nextpos[1]][nextpos[0]] == '#'){
            switch(dir%4){
                case 0: nextpos[1]++; break;
                case 1: nextpos[0]--; break;
                case 2: nextpos[1]--; break;
                case 3: nextpos[0]++; break;
            }
            dir++;
        }
        
        //check if position is in list visited with same direction
            std::vector<int> a ={nextpos[0],nextpos[1],dir%4};
            auto it = std::find(points2.begin(),points2.end(),a);
            if(it != points2.end()){
                total++;
                points2.push_back({nextpos[0],nextpos[1],dir%4});
                break;
            }
            points2.push_back({nextpos[0],nextpos[1],dir%4});
        
        switch(dir%4){
            case 0: nextpos[1]--; break;
            case 1: nextpos[0]++; break;
            case 2: nextpos[1]++; break;
            case 3: nextpos[0]--; break;
        }
        }
        board[point[1]][point[0]] = '.';
    }
    return total;
}