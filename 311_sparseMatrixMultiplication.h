//
// Created by 王柯 on 11/15/22.
//

#ifndef LEETCODE_311_SPARSEMATRIXMULTIPLICATION_H
#define LEETCODE_311_SPARSEMATRIXMULTIPLICATION_H

#include "solution.h"

class SparseMatrixMulitplication {
public:
    vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int l = 0; l < k; ++l) {
                if (mat1[i][l] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    res[i][j] += mat1[i][l] * mat2[l][j];
                }
            }
        }

        return res;
    }
};

#endif //LEETCODE_311_SPARSEMATRIXMULTIPLICATION_H
