//
// Created by Ke Wang on 10/22/24.
//

#ifndef INC_317_SHORTESTDISTANCEFROMALLBUILDINGS_H
#define INC_317_SHORTESTDISTANCEFROMALLBUILDINGS_H

#include "solution.h"

class ShortestDistanceFromAllBuildings : public solution {
private:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> sum;
    vector<vector<int>> visitedCnt;

    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), num = 0;
        sum.resize(n, vector<int>(m, 0));
        visitedCnt.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++num;
                    bfs(i, j, num, grid);
                }
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 && visitedCnt[i][j] == num) {
                    res = min(res, sum[i][j]);
                }
            }
        }
        return res == INT32_MAX ? -1 : res;
    }

    void bfs(int x, int y, int num, vector<vector<int>>& grid) {
        // return false if a building is unreachable
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<vector<int>> qq;
        qq.push({x, y, 0});
        visited[x][y] = true;
        while (!qq.empty()) {
            vector<int> &tmp = qq.front();
            int i = tmp[0], j = tmp[1], dis = tmp[2];
            qq.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj] == 0) {
                    // update sum
                    sum[ni][nj] += dis + 1;
                    // update visitedCnt
                    ++visitedCnt[ni][nj];
                    visited[ni][nj] = true;
                    qq.push({ni, nj, dis + 1});
                }
            }

        }
    }

};

#endif //INC_317_SHORTESTDISTANCEFROMALLBUILDINGS_H
