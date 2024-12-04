#include "day4.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int d4p1(){
    int total = 0;
    std::vector<std::string> board;
    std::string inp;
    while(std::getline(std::cin, inp)){
        board.push_back(inp);
    }
    int width = board[0].size() - 3;
    int depth = board.size() - 3;
    for (size_t y = 0; y< board.size(); y++) {
        for (size_t x = 0; x < board[x].size(); x++) {
            if(board[y][x] != 'X'){
                continue;
            }
            if(y >= 3 && x >= 3){
                //northwest
                if(board[y-1][x-1] == 'M' && board[y-2][x-2] == 'A' && board[y-3][x-3] == 'S'){
                    total++;
                }
            }
            if(y >= 3){
                //north
                if(board[y-1][x] == 'M' && board[y-2][x] == 'A' && board[y-3][x] == 'S'){
                    total++;
                }
            }
            if(y >= 3 && x < width){
                //northeast
                if(board[y-1][x+1] == 'M' && board[y-2][x+2] == 'A' && board[y-3][x+3] == 'S'){
                    total++;
                }
            }
            if(x < width){
                //east
                if(board[y][x+1] == 'M' && board[y][x+2] == 'A' && board[y][x+3] == 'S'){
                    total++;
                }
            }
            if(y < depth && x < width){
                //southeast
                if(board[y+1][x+1] == 'M' && board[y+2][x+2] == 'A' && board[y+3][x+3] == 'S'){
                    total++;
                }
            }
            if(y < depth){
                //south
                if(board[y+1][x] == 'M' && board[y+2][x] == 'A' && board[y+3][x] == 'S'){
                    total++;
                }
            }
            if(y < depth && x >= 3){
                //southwest
                if(board[y+1][x-1] == 'M' && board[y+2][x-2] == 'A' && board[y+3][x-3] == 'S'){
                    total++;
                }
            }
            if(x >= 3){
                //west
                if(board[y][x-1] == 'M' && board[y][x-2] == 'A' && board[y][x-3] == 'S'){
                    total++;
                }
            }
        }
    }
    return total;
}

int d4p2(){
    int total = 0;
    std::vector<std::string> board;
    std::string inp;
    while(std::getline(std::cin, inp)){
        board.push_back(inp);
    }
    int width = board[0].size() - 1;
    int depth = board.size() - 1;
    for (size_t y = 0; y< board.size(); y++) {
        for (size_t x = 0; x < board[x].size(); x++) {
            if(board[y][x] != 'A'){
                continue;
            }
            if(y>0 && x>0 && y<depth && x<width){
                if(((board[y-1][x-1] == 'M' && board[y+1][x+1] == 'S') || (board[y-1][x-1] == 'S' && board[y+1][x+1] == 'M')) && ((board[y-1][x+1] == 'M' && board[y+1][x-1] == 'S') || (board[y-1][x+1] == 'S' && board[y+1][x-1] == 'M'))){
                    total++;
                }
            }
        }
    }
    return total;
}