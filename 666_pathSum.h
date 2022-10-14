//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_666_PATHSUM_H
#define LEETCODE_666_PATHSUM_H

#include "solution.h"

class PathSum : public solution {
public:
    int pathSum(vector<int> &nums) {
        int res = 0, len = nums.size();
        vector<vector<int> > tree(6, vector<int>(30, -1));
        for (auto i : nums) {
            int h = i / 100;
            int t = (i % 100) / 10 - 1;
            int u = i % 10;
            tree[h][t] = u;
        }
        for (auto i : nums) {
            int h = i / 100;
            int t = (i % 100) / 10 - 1;
            int u = i % 10;
            if (tree[h + 1][t * 2] != -1 || tree[h + 1][t * 2 + 1] != -1) continue;
            while (h > 0) {
                res += u;
                --h;
                t /= 2;
                u = tree[h][t];
            }
        }

        return res;
    }

    void check() {
        vector<int> nums{113, 215, 221};
        int res = pathSum(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_666_PATHSUM_H
