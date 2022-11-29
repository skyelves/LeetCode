//
// Created by 王柯 on 11/28/22.
//

#ifndef LEETCODE_329_LONGESTINCREASINGPATH_H
#define LEETCODE_329_LONGESTINCREASINGPATH_H

#include "solution.h"

class LongestIncreasingPath : public solution {
public:
    int dir[4][2] = {{-1, 0},
                     {1,  0},
                     {0,  -1},
                     {0,  1}};

    int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int res = 1, len = matrix.size(), width = matrix[0].size();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < len && ny >= 0 && ny < width) {
                if (matrix[nx][ny] > matrix[x][y]) {
                    int tmp = dfs(nx, ny, matrix, dp);
                    res = max(res, tmp + 1);
                }
            }
        }
        dp[x][y] = res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int res = 1, len = matrix.size(), width = matrix[0].size();
        vector<vector<int>> dp(len, vector<int>(width, -1));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                int tmp = dfs(i, j, matrix, dp);
                res = max(res, tmp);
            }
        }

        return res;
    }

    void check() {
        vector<vector<int>> matrix{{9, 9, 4},
                                   {6, 6, 8},
                                   {2, 1, 1}};
        int res = longestIncreasingPath(matrix);
        cout << res << endl;
    }
};

#endif //LEETCODE_329_LONGESTINCREASINGPATH_H
