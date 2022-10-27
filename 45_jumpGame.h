//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_45_JUMPGAME_H
#define LEETCODE_45_JUMPGAME_H

#include "solution.h"

class JumpGame2 : public solution {
public:
    int jump(vector<int>& nums) {
        /*
         * dp
         */
//        int len = nums.size();
//        vector<int> dp(len, INT_MAX);
//        dp[0] = 0;
//        for (int i = 0; i < len; ++i) {
//            for (int j = 1; j <= nums[i]; ++j) {
//                if (i + j < len) {
//                    dp[i + j] = min(dp[i + j], dp[i] + 1);
//                }
//            }
//        }
//
//        return dp[len - 1];

        /*
         * greedy
         */
        int len = nums.size();
        int idx = 0, res = 0;
        while(idx < len - 1) {
            int tmp = 0, tmpIdx = idx + 1;
            for (int i = 1; i <= nums[idx]; ++i) {
                if (idx + i == len - 1) {
                    tmpIdx = len - 1;
                    break;
                }
                if (nums[idx + i] + idx + i >= tmp) {
                    tmp = nums[idx + i] + idx + i;
                    tmpIdx = idx + i;
                }
            }
            ++res;
            idx = tmpIdx;
        }
        return res;
    }
};

#endif //LEETCODE_45_JUMPGAME_H
