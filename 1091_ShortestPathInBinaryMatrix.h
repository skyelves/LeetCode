//
// Created by Ke Wang on 10/20/24.
//

#ifndef INC_1091_SHORTESTPATHINBINARYMATRIX_H
#define INC_1091_SHORTESTPATHINBINARYMATRIX_H

#include "solution.h"

class ShortestPathInBinaryMatrix : public solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));
        // bfs
        queue<vector<int>> qq;
        qq.push({0, 0, 1});
        dis[0][0] = 1;
        while (!qq.empty()) {
            vector<int> &tmp = qq.front();
            for (int i = -1; i <2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int newI = tmp[0] + i, newJ = tmp[1] + j;
                    if (newI >= 0 && newI < n
                        && newJ >= 0 && newJ < m
                        && dis[newI][newJ] == -1 && grid[newI][newJ] == 0) {
                        dis[newI][newJ] = tmp[2] + 1;
                        qq.push({newI, newJ, dis[newI][newJ]});
                    }
                }
            }
            qq.pop();
        }

        return dis[n - 1][m - 1];
    }
};

#endif //INC_1091_SHORTESTPATHINBINARYMATRIX_H
