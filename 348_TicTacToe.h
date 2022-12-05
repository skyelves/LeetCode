//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_348_TICTACTOE_H
#define LEETCODE_348_TICTACTOE_H

#include "solution.h"

class TicTacToe {
public:
    int n;
    vector<int> rowCnt[2], colCnt[2];
    int dia[2][2] = {0};
    
    TicTacToe(int n) {
        this->n = n;
        rowCnt[0].resize(n, 0);
        rowCnt[1].resize(n, 0);
        colCnt[0].resize(n, 0);
        colCnt[1].resize(n, 0);
    }

    int move(int row, int col, int player) {
        ++rowCnt[player - 1][row];
        ++colCnt[player - 1][col];
        if (row == col)
            ++dia[player - 1][0];
        if (row + col == n - 1)
            ++dia[player - 1][1];
        if (rowCnt[player - 1][row] == n || colCnt[player - 1][col] == n || dia[player - 1][0] == n || dia[player - 1][1] == n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

#endif //LEETCODE_348_TICTACTOE_H
