//
// Created by 王柯 on 7/26/22.
//

#ifndef LEETCODE_2249_COUNTLATTICEPOINTS_H
#define LEETCODE_2249_COUNTLATTICEPOINTS_H

#include "solution.h"

class CountLatticePoints : public solution {
public:

    int countLatticePoints(vector<vector<int>> &circles) {
        set<pair<int, int> > exists;
        int res = 0;
        int circles_num = circles.size();
        for (int i = 0; i < circles_num; ++i) {
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            int r2 = r * r;
            for (int j = x - r; j <= x + r; ++j) {
                for (int k = y - r; k <= y + r; ++k) {
                    int tmp_r2 = (j - x) * (j - x) + (k - y) * (k - y);
                    if (tmp_r2 <= r2) {
                        if (exists.find({j, k}) == exists.end()) {
                            res++;
                            exists.insert({j, k});
                        }
                    }
                }
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2249_COUNTLATTICEPOINTS_H
