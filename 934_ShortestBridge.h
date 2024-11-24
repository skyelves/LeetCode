//
// Created by Ke Wang on 11/24/24.
//

#ifndef INC_934_SHORTESTBRIDGE_H
#define INC_934_SHORTESTBRIDGE_H

#include "solution.h"

class ShortestBridge : public solution {
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> island;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, visited, island);
                    while (!island.empty()) {
                        int x = island.front()[0], y = island.front()[1], dis = island.front()[2];
                        island.pop();
                        for (int i = 0; i < 4; ++i) {
                            int nx = x + dir[i][0], ny = y + dir[i][1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                if (grid[nx][ny] == 0) {
                                    island.push({nx, ny, dis + 1});
                                } else {
                                    return dis;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>> &visited, queue<vector<int>> &island) {
        visited[x][y] = true;
        island.push({x, y, 0});
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 1) {
                dfs(nx, ny, grid, visited, island);
            }
        }
    }
};

#endif //INC_934_SHORTESTBRIDGE_H
