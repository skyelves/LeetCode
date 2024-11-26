//
// Created by Ke Wang on 11/25/24.
//

#ifndef INC_130_SURROUNDEDREGIONS_H
#define INC_130_SURROUNDEDREGIONS_H

#include "solution.h"

class SurroundedRegions : public solution {
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board, visited);
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, visited);
            }
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                dfs(0, j, board, visited);
            }
            if (board[n - 1][j] == 'O') {
                dfs(n - 1, j, board, visited);
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board,  vector<vector<bool>> &visited) {
        if (visited[x][y]) {
            return;
        }
        int n = board.size(), m = board[0].size();
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, board, visited);
            }
        }
    }
};

#endif //INC_130_SURROUNDEDREGIONS_H
