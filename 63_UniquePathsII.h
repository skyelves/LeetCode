//
// Created by Admin on 9/30/2024.
//

#ifndef LEETCODE_63_UNIQUEPATHSII_H
#define LEETCODE_63_UNIQUEPATHSII_H

#include "solution.h"

class UniquePathsII : public solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> uniquePaths(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            uniquePaths[i][0] = 1;
        }
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            uniquePaths[0][j] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    uniquePaths[i][j] = 0;
                } else {
                    uniquePaths[i][j] = uniquePaths[i - 1][j] + uniquePaths[i][j - 1];
                }
            }
        }

        return uniquePaths[n - 1][m - 1];
    }
};

#endif //LEETCODE_63_UNIQUEPATHSII_H
