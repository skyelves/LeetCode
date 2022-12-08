//
// Created by 王柯 on 12/8/22.
//

#ifndef LEETCODE_1658_MINOPERATIONSTOREDUCEXTOZERO_H
#define LEETCODE_1658_MINOPERATIONSTOREDUCEXTOZERO_H

#include "solution.h"

class MinOperationsToReduceXToZero : public solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int res = INT_MAX, len = nums.size();
        vector<int> prefixSum(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        int sum = prefixSum[len];
        int l = 0, r = 0;
        while (l <= r && r <= len) {
            int tmp = prefixSum[l] + sum - prefixSum[r];
            if (tmp > x) {
                ++r;
            } else if (tmp == x) {
                res = min(res, l + len - r);
                ++r;
            } else {
                ++l;
            }
        }

        return res == INT_MAX ? -1 : res;
    }

    void check() {
        vector<int> nums{1, 1, 4, 2, 3};
        int x = 5;
        int res = minOperations(nums, x);
        cout << res << endl;
    }
};

#endif //LEETCODE_1658_MINOPERATIONSTOREDUCEXTOZERO_H
