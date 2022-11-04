//
// Created by 王柯 on 11/3/22.
//

#ifndef LEETCODE_286_WALLSANDGATES_H
#define LEETCODE_286_WALLSANDGATES_H

#include "solution.h"

class WallsAndGates : public solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int dir[4][2] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};
        int len = rooms.size(), width = rooms[0].size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                if (rooms[i][j] == 0) {
                    queue<pair<int, int>> qq;
                    qq.push({i, j});
                    while (!qq.empty()) {
                        auto curr = qq.front();
                        int dis = rooms[curr.first][curr.second] + 1;
                        qq.pop();
                        for (int k = 0; k < 4; ++k) {
                            int ni = curr.first + dir[k][0], nj = curr.second + dir[k][1];
                            if (ni >= 0 && ni < len && nj >= 0 && nj < width) {
                                if (rooms[ni][nj] > dis) {
                                    rooms[ni][nj] = dis;
                                    qq.push({ni, nj});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void check() {
        vector<vector<int>> rooms{{2147483647, -1,         0,          2147483647},
                                  {2147483647, 2147483647, 2147483647, -1},
                                  {2147483647, -1,         2147483647, -1},
                                  {0,          -1,         2147483647, 2147483647}};
        wallsAndGates(rooms);
        for (auto &i : rooms) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_286_WALLSANDGATES_H
