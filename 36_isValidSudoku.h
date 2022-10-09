//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_36_ISVALIDSUDOKU_H
#define LEETCODE_36_ISVALIDSUDOKU_H

#include "solution.h"

class IsValidSudoku : public solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            bool visited[10] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (visited[num]) {
                    return false;
                } else {
                    visited[num] = true;
                }
            }
            bool visited1[10] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;
                int num = board[j][i] - '1';
                if (visited1[num]) {
                    return false;
                } else {
                    visited1[num] = true;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                bool visited[10] = {false};
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i * 3 + k][j * 3 + l] == '.')
                            continue;
                        int num = board[i * 3 + k][j * 3 + l] - '1';
                        if (visited[num]) {
                            return false;
                        } else {
                            visited[num] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

#endif //LEETCODE_36_ISVALIDSUDOKU_H
