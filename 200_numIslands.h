//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_200_NUMISLANDS_H
#define LEETCODE_200_NUMISLANDS_H

#include "solution.h"

class NumIslands : public solution {
public:
    int dir[4][2] = {{-1, 0},
                     {1,  0},
                     {0,  -1},
                     {0,  1}};

    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool> > &visited) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0')
            return;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            dfs(x + dir[i][0], y + dir[i][1], grid, visited);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int res = 0;
        int len = grid.size(), width = grid[0].size();
        vector<vector<bool> > visited(len, vector<bool>(width, false));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return res;
    }

    void check() {
        vector<vector<char>> grid{
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        int res = numIslands(grid);
        cout << res << endl;
    }
};

#endif //LEETCODE_200_NUMISLANDS_H
