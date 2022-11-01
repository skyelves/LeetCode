//
// Created by 王柯 on 10/31/22.
//

#ifndef LEETCODE_213_HOUSEROBBER2_H
#define LEETCODE_213_HOUSEROBBER2_H

#include "solution.h"

class HouseRobber2 : public solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len - 1; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int res = dp[len - 2];
        dp[0] = nums[1];
        dp[1] = max(nums[1], nums[2]);
        for (int i = 2; i < len - 1; ++i) {
            dp[i] = max(dp[i - 2] + nums[i + 1], dp[i - 1]);
        }
        res = max(res, dp[len - 2]);
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_213_HOUSEROBBER2_H
