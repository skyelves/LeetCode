//
// Created by 王柯 on 8/5/22.
//

#ifndef LEETCODE_377_COMBINATIONSUM4_H
#define LEETCODE_377_COMBINATIONSUM4_H

#include "solution.h"

class CombinationSum4 : public solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int res = 0;
        int len = nums.size();
        uint64_t **dp = new uint64_t *[target + 1];
        for (int i = 0; i <= target; ++i) {
            dp[i] = new uint64_t[target + 1];
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] <= target)
                dp[1][nums[i]] = 1;
        }
        for (int i = 2; i <= target; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int k = 0; k < len; ++k) {
                    if (j > nums[k]) {
                        dp[i][j] += dp[i - 1][j - nums[k]];
                    }
                }
            }
        }
        for (int i = 1; i <= target; ++i) {
            res += dp[i][target];
        }
        return res;
    }

    void check() {
        vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210,
                         220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400,
                         410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590,
                         600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780,
                         790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970,
                         980, 990, 111};
        int target = 999;
        int res = combinationSum4(nums, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_377_COMBINATIONSUM4_H
