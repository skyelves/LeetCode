//
// Created by 王柯 on 8/27/23.
//

#ifndef LEETCODE_403_FROGJUMP_H
#define LEETCODE_403_FROGJUMP_H

#include "solution.h"

class FrogJump : public solution {
    bool canCross(vector<int> &stones) {
        vector<set<int>> dis(stones.size());
        dis[0].insert(0);
        for (int i = 0; i < stones.size() - 1; ++i) {
            for (auto &j : dis[i]) {
                for (int s = -1; s < 2; ++s) {
                    if (j + s > 0) {
                        for (int k = 1; k < stones.size() - i; ++k) {
                            int tmpDis = stones[i + k] - stones[i];
                            if (tmpDis == j + s) {
                                dis[i + k].insert(j + s);
                            } else if (tmpDis > j + s)
                                break;
                        }
                    }
                }
            }
        }
        return dis[stones.size() - 1].size() != 0;
    }

    void check() {
        vector<int> stones{0,1,2,3,4,8,9,11};
        cout << canCross(stones) << endl;
    }
};

#endif //LEETCODE_403_FROGJUMP_H
