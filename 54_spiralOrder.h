//
// Created by 王柯 on 11/2/22.
//

#ifndef LEETCODE_54_SPIRALORDER_H
#define LEETCODE_54_SPIRALORDER_H

#include "solution.h"

class SpiralOrder : public solution {
public:
    int dir[4][2] = {{0,  1},
                     {1,  0},
                     {0,  -1},
                     {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int len = matrix.size(), width = matrix[0].size(), num = len * width;
        int cnt = 0, direction = 0, x = 0, y = 0;
        vector<vector<bool>> visited(len, vector<bool>(width, false));
        while (cnt < num) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nx = x + dir[direction][0], ny = y + dir[direction][1];
            if (nx >= 0 && nx < len && ny >= 0 && ny < width && !visited[nx][ny]) {
                x = nx;
                y = ny;
            } else {
                direction = (direction + 1) % 4;
                x = x + dir[direction][0];
                y = y + dir[direction][1];
            }
            ++cnt;
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_54_SPIRALORDER_H
