//
// Created by Admin on 10/4/2024.
//

#ifndef LEETCODE_498_DIAGNOLTRAVERSE_H
#define LEETCODE_498_DIAGNOLTRAVERSE_H

#include "solution.h"

class DiagnolTraverse : public solution {
private:
    vector<vector<int>> direction{{-1, 1},
                                  {1,  -1}};

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        const int n = mat.size(), m = mat[0].size(), total = n * m;
        int x = 0, y = 0, cnt = 0, dir = 0;
        vector<int> res(total, 0);
        while (cnt < total) {
            res[cnt] = mat[x][y];
            ++cnt;
            next(x, y, dir, n, m);
        }
        return res;
    }

    void next(int &x, int &y, int &dir, const int n, const int m) {
        if (dir == 0) {
            if (y == m - 1) {
                ++x;
                dir = 1 - dir;
                return;
            } else if (x == 0) {
                ++y;
                dir = 1 - dir;
                return;
            }
        } else if (dir == 1){
            if (x == n - 1) {
                ++y;
                dir = 1 - dir;
                return;
            } else if (y == 0) {
                ++x;
                dir = 1 - dir;
                return;
            }
        }

        x += direction[dir][0];
        y += direction[dir][1];
    }

    void check() {
        vector<vector<int>> mat{{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
        vector<int> res = findDiagonalOrder(mat);
        for (int i: res) {
            cout << i << " ";
        }
    }
};

#endif //LEETCODE_498_DIAGNOLTRAVERSE_H
