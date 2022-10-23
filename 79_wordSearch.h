//
// Created by 王柯 on 10/23/22.
//

#ifndef LEETCODE_79_WORDSEARCH_H
#define LEETCODE_79_WORDSEARCH_H

#include "solution.h"

class wordSearch : public solution {
public:
    int dir[4][2] = {{-1, 0},
                     {1,  0},
                     {0,  1},
                     {0,  -1}};

    bool dfs(vector<vector<char>> &board, string &word, set<pair<int, int>> &visited, int idx, int x, int y) {
        int len = board.size(), width = board[0].size();
        if (visited.find({x, y}) != visited.end())
            return false;
        if (word[idx] != board[x][y])
            return false;
        if (idx == word.size() - 1)
            return true;
        visited.insert({x, y});
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < len && ny >= 0 && ny < width) {
                if (dfs(board, word, visited, idx + 1, nx, ny))
                    return true;
            }
        }
        visited.erase({x, y});
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        set<pair<int, int>> visited;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, visited, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    void check() {
        vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                                   {'S', 'F', 'C', 'S'},
                                   {'A', 'D', 'E', 'E'}};
        string word = "ABCCED";
        bool res = exist(board, word);
        cout << res << endl;
    }
};

#endif //LEETCODE_79_WORDSEARCH_H
