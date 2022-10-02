//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1274_COUNTSHIPS_H
#define LEETCODE_1274_COUNTSHIPS_H

#include "solution.h"

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft) {};
};

class CountShips {
public:
    int countShips(Sea &sea, vector<int> topRight, vector<int> bottomLeft) {
        int X1 = bottomLeft[0], Y1 = bottomLeft[1], X2 = topRight[0], Y2 = topRight[1];
        if (X1 > X2 || Y1 > Y2)
            return 0;
        if (!sea.hasShips(topRight, bottomLeft))
            return 0;
        if (X1 == X2 && Y1 == Y2) {
            return 1;
        } else {
            int midX = (X1 + X2) / 2, midY = (Y1 + Y2) / 2;
            return countShips(sea, vector<int>{midX, Y2}, vector<int>{X1, midY + 1}) +
                   countShips(sea, topRight, vector<int>{midX + 1, midY + 1}) +
                   countShips(sea, vector<int>{midX, midY}, bottomLeft) +
                   countShips(sea, vector<int>{X2, midY}, vector<int>{midX + 1, Y1});

        }
    }
};

#endif //LEETCODE_1274_COUNTSHIPS_H
