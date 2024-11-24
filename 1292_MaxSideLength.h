//
// Created by Ke Wang on 11/23/24.
//

#ifndef INC_1292_MAXSIDELENGTH_H
#define INC_1292_MAXSIDELENGTH_H

#include "solution.h"

class MaxSideLength : public solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int res = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] <= threshold) {
                    res = 1;
                }
            }
        }
        if (res == 0) {
            return res;
        }
        vector<vector<int>> preSum(n, vector<int>(m, 0));
        preSum[0][0] = mat[0][0];
        for (int i = 1; i < n; ++i) {
            preSum[i][0] = preSum[i - 1][0] + mat[i][0];
        }
        for (int i = 1; i < m; ++i) {
            preSum[0][i] = preSum[0][i - 1] + mat[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int l = res; l < min(n - i, m - j); ++l) {
                    int tmp = preSum[i + l][j + l];
                    if (i != 0) {
                        tmp -= preSum[i - 1][j + l];
                    }
                    if (j != 0) {
                        tmp -= preSum[i + l][j - 1];
                    }
                    if (i != 0 && j != 0) {
                        tmp += preSum[i - 1][j - 1];
                    }
                    if (tmp <= threshold) {
                        res = l + 1;
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};

#endif //INC_1292_MAXSIDELENGTH_H
