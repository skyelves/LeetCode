//
// Created by 王柯 on 11/27/22.
//

#ifndef LEETCODE_300_LENGTHOFLIS_H
#define LEETCODE_300_LENGTHOFLIS_H

#include "solution.h"

class LengthOfLIS : public solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }

        return dp.size();
    }

    void check() {

    }
};

#endif //LEETCODE_300_LENGTHOFLIS_H
