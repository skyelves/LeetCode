//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_48_ROTATEIMAGE_H
#define LEETCODE_48_ROTATEIMAGE_H

#include "solution.h"

class RotateImage : public solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // i, j -> j, n - i
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }

    void check() {

    }
};

#endif //LEETCODE_48_ROTATEIMAGE_H
