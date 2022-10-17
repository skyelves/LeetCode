//
// Created by 王柯 on 10/17/22.
//

#ifndef LEETCODE_773_SLIDINGPUZZLE_H
#define LEETCODE_773_SLIDINGPUZZLE_H

#include "solution.h"

class SlidingPuzzle : public solution {
public:
    int dir[4][2] = {{0,  -1},
                     {0,  1},
                     {-1, 0},
                     {1,  0}};

    int slidingPuzzle(vector<vector<int>> &board) {
        vector<bool> visited(555555, false);
        queue<pair<vector<vector<int>>, int>> qq;
        qq.push({board, 0});
        while (!qq.empty()) {
            auto tmp = qq.front();
            auto tmpB = tmp.first;
            int tmpS = tmp.second;
            qq.pop();
            int boardNum = tmpB[0][0] * 100000 + tmpB[0][1] * 10000 + tmpB[0][2] * 1000 +
                           tmpB[1][0] * 100 + tmpB[1][1] * 10 + tmpB[1][2];
            if (boardNum == 123450) {
                return tmpS;
            }
            if (visited[boardNum])
                continue;
            visited[boardNum] = true;
            int x = -1, y = -1;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (tmpB[i][j] == 0) {
                        x = i;
                        y = j;
                        break;
                    }
                }
                if (x != -1)
                    break;
            }
            for (int i = 0; i < 4; ++i) {
                int newx = x + dir[i][0], newy = y + dir[i][1];
                if (newx >= 0 && newx < 2 && newy >= 0 && newy < 3) {
                    //todo: swap (x,y) with (newx, newy)
                    vector<vector<int>> newBoard = tmpB;
                    newBoard[x][y] = tmpB[newx][newy];
                    newBoard[newx][newy] = 0;
                    qq.push({newBoard, tmpS + 1});
                }
            }
        }
        return -1;
    }

    void check() {
        vector<vector<int>> board{{4, 1, 2},
                                  {5, 0, 3}};
        int res = slidingPuzzle(board);
        cout << res << endl;
    }
};

#endif //LEETCODE_773_SLIDINGPUZZLE_H
