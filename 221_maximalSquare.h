//
// Created by 王柯 on 10/14/22.
//

#ifndef LEETCODE_221_MAXIMALSQUARE_H
#define LEETCODE_221_MAXIMALSQUARE_H

#include "solution.h"

class MaximalSquare : public solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int res = 0;
        int len = matrix.size(), width = matrix[0].size();
        vector<vector<int> > dp(len + 2, vector<int>(width + 2, 0));
        for (int i = 0; i < len; ++i) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = 1;
            }
        }
        for (int i = 0; i < width; ++i) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                res = 1;
            }
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }

    void check() {
        vector<vector<char> > matrix{{'0', '0', '0', '1'},
                                     {'1', '1', '0', '1'},
                                     {'1', '1', '1', '1'},
                                     {'0', '1', '1', '1'},
                                     {'0', '1', '1', '1'}};
        int res = maximalSquare(matrix);
        cout << res << endl;
    }
};

#endif //LEETCODE_221_MAXIMALSQUARE_H
