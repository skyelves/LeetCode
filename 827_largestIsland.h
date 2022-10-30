//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_827_LARGESTISLAND_H
#define LEETCODE_827_LARGESTISLAND_H

#include "solution.h"

class LargestIsland : public solution {
public:
    int largestIsland(vector<vector<int>> &grid) {
        int dir[4][2] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};
        int res = 0;
        int len = grid.size(), width = grid[0].size(), num = 0;
        vector<vector<int>> iNum(len, vector<int>(width, 0));
        map<int, int> mm;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                if (iNum[i][j] == 0 && grid[i][j] == 1) {
                    ++num;
                    int cnt = 1;
                    // bfs
                    queue<pair<int, int>> qq;
                    qq.push({i, j});
                    iNum[i][j] = num;
                    while (!qq.empty()) {
                        auto tmp = qq.front();
                        qq.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = tmp.first + dir[k][0], ny = tmp.second + dir[k][1];
                            if (nx >= 0 && nx < len && ny >= 0 && ny < width && iNum[nx][ny] == 0 &&
                                grid[nx][ny] == 1) {
                                iNum[nx][ny] = num;
                                ++cnt;
                                qq.push({nx, ny});
                            }
                        }
                    }
                    mm[num] = cnt;
                    res = max(res, cnt);
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 0) {
                    int tmp = 1;
                    set<int> nearbyIsland;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dir[k][0], ny = j + dir[k][1];
                        if (nx >= 0 && nx < len && ny >= 0 && ny < width && iNum[nx][ny] != 0) {
                            nearbyIsland.insert(iNum[nx][ny]);
                        }
                    }
                    for (auto iter = nearbyIsland.begin(); iter != nearbyIsland.end(); ++iter) {
                        tmp += mm[*iter];
                    }
                    res = max(res, tmp);
                }
            }
        }

        return res;
    }

    void check() {
        vector<vector<int>> grid{{1, 1},
                                 {1, 1}};
        int res = largestIsland(grid);
        cout << res << endl;
    }
};

#endif //LEETCODE_827_LARGESTISLAND_H
