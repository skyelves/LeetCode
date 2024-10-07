//
// Created by Admin on 10/6/2024.
//

#ifndef LEETCODE_766_TOEPLITZMATRIX_H
#define LEETCODE_766_TOEPLITZMATRIX_H

#include "solution.h"

class ToeplitzMatrix : public solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            int num = matrix[i][0];
            for (int j = 1; j < min(n - i, m); ++j) {
                if (num != matrix[i + j][j]) {
                    return false;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int num = matrix[0][j];
            for (int i = 1; i < min(n, m - j); ++i) {
                if (num != matrix[i][i + j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODE_766_TOEPLITZMATRIX_H
