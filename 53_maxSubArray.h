//
// Created by 王柯 on 9/12/22.
//

#ifndef LEETCODE_53_MAXSUBARRAY_H
#define LEETCODE_53_MAXSUBARRAY_H

#include "solution.h"

class MaxSubArray : public solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        int len = nums.size();
        int *dp = new int[len];
        memset(dp, 0, sizeof(int) * len);
        dp[0] = nums[0];
        res = max(res, dp[0]);
        for (int i = 1; i < len; ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }

    void check() {
        vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
        int res = maxSubArray(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_53_MAXSUBARRAY_H
