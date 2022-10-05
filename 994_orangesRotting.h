//
// Created by 王柯 on 10/4/22.
//

#ifndef LEETCODE_994_ORANGESROTTING_H
#define LEETCODE_994_ORANGESROTTING_H

#include "solution.h"

class OrangesRotting : public solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int dir[4][2] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};
        int res = 0;
        int freshCnt = 0;
        int len = grid.size(), width = grid[0].size();
        // find all the rot orange
        queue<pair<int, int> > rot;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < width; ++j) {
                freshCnt += (grid[i][j] == 1);
                if (grid[i][j] == 2) {
                    rot.push({i, j});
                }
            }
        }
        queue<pair<int, int>> next;
        while (freshCnt != 0 && !rot.empty()) {
            queue<pair<int, int>> next;
            while (!rot.empty()) {
                auto tmp = rot.front();
                rot.pop();
                for (int i = 0; i < 4; ++i) {
                    int ni = tmp.first + dir[i][0], nj = tmp.second + dir[i][1];
                    if (ni >= 0 && ni < len && nj >= 0 && nj < width && grid[ni][nj] == 1) {
                        freshCnt--;
                        grid[ni][nj] = 2;
                        next.push({ni, nj});
                    }
                }
            }
            res++;
            rot = next;
        }

        return freshCnt == 0 ? res : -1;
    }

    void check() {
        vector<vector<int>> grid{{2, 1, 1},
                                 {1, 1, 0},
                                 {0, 1, 1}};
        int res = orangesRotting(grid);
        cout << res << endl;
    }
};

#endif //LEETCODE_994_ORANGESROTTING_H
