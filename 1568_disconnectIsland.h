//
// Created by Admin on 8/10/2024.
//

#ifndef LEETCODE_1568_DISCONNECTISLAND_H
#define LEETCODE_1568_DISCONNECTISLAND_H

#include "solution.h"

class DisconnectIsland : public solution {
private:
    int direction[4][2] = {{-1, 0},
                           {1,  0},
                           {0,  1},
                           {0,  -1}};

public:
    int minDays(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int landCnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                landCnt += grid[i][j];
            }
        }
        if (!isConnected(grid, landCnt)) {
            return 0;
        }
        --landCnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (!isConnected(grid, landCnt)) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        // the maximum is 2, that is, make the corner land to be a seperate island
        return 2;
    }

    int recursiveExpand(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            res += recursiveExpand(grid, visited, i + direction[k][0], j + direction[k][1]);
        }
        return res;
    }

    bool isConnected(vector<vector<int>> &grid, int landCnt) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int tmpCnt = recursiveExpand(grid, visited, i, j);
                    if (tmpCnt != landCnt) {
                        return false;
                    }
                    return true;
                }
            }
        }
        return false;
    }

    void check() {

    }
};

#endif //LEETCODE_1568_DISCONNECTISLAND_H
