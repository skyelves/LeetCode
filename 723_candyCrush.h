//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_723_CANDYCRUSH_H
#define LEETCODE_723_CANDYCRUSH_H

#include "solution.h"

class CandyCrush : public solution {
public:
    bool ifCrush(vector<vector<int>> &board, int ii, int jj) {
        if (board[ii][jj] == 0)
            return false;
        int len = board.size(), width = board[0].size();
        int cnt = 1;
        int i = ii + 1, j = jj;
        while (i < len && board[i][j] == board[ii][jj] && cnt < 3) {
            i++;
            cnt++;
        }
        i = ii - 1, j = jj;
        while (i >= 0 && board[i][j] == board[ii][jj] && cnt < 3) {
            i--;
            cnt++;
        }
        if (cnt == 3)
            return true;
        cnt = 1;
        i = ii, j = jj + 1;
        while (j < width && board[i][j] == board[ii][jj] && cnt < 3) {
            j++;
            cnt++;
        }
        i = ii, j = jj - 1;
        while (j >= 0 && board[i][j] == board[ii][jj] && cnt < 3) {
            j--;
            cnt++;
        }
        return cnt == 3;
    }

    void fall(vector<vector<int>> &board) {
        int len = board.size(), width = board[0].size();
        for (int i = 0; i < width; ++i) {
            for (int j = len - 1, idx = len - 1; j >= 0; --j) {
                if (board[j][i] != 0) {
                    board[idx][i] = board[j][i];
                    if (j != idx)
                        board[j][i] = 0;
                    idx--;
                }
            }
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int len = board.size(), width = board[0].size();
        int cnt = 1;
        while (cnt != 0) {
            vector<vector<int>> oldBoard = board;
            cnt = 0;
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < width; ++j) {
                    bool tmp = ifCrush(oldBoard, i, j);
                    if (tmp) {
                        board[i][j] = 0;
                        cnt++;
                    }
                }
            }
            fall(board);
        }
        return board;
    }

    void check() {
        vector<vector<int>> board{{1, 3, 5, 5, 2},
                                  {3, 4, 3, 3, 1},
                                  {3, 2, 4, 5, 2},
                                  {2, 4, 4, 5, 5},
                                  {1, 4, 4, 1, 1}};
        auto res = candyCrush(board);
        for (auto i : board) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_723_CANDYCRUSH_H
