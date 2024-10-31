//
// Created by Ke Wang on 10/30/24.
//

#ifndef INC_1197_MINIMUMKNIGHTMOVES_H
#define INC_1197_MINIMUMKNIGHTMOVES_H

#include "solution.h"

class MinimumKnightMoves : public solution {
private:
    vector<vector<int>> dir{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    vector<vector<int>> dis;
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) {
            return 0;
        }
        x = abs(x);
        y = abs(y);
        dis.resize(x + 10, vector<int>(y + 10, 0));
        queue<vector<int>> qq;
        qq.push({0, 0, 0});
        bool flag = true;
        while (flag) {
            auto tmp = qq.front();
            qq.pop();
            for (int i = 0; i < 8; ++i) {
                int nx = abs(tmp[0] + dir[i][0]), ny = abs(tmp[1] + dir[i][1]);
                if (nx < x + 10 && ny < y + 10 && dis[nx][ny] == 0) {
                    qq.push({nx, ny, tmp[2] + 1});
                    dis[nx][ny] = tmp[2] + 1;
                    if (nx == x && ny == y) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        return dis[x][y];
    }
};

#endif //INC_1197_MINIMUMKNIGHTMOVES_H
