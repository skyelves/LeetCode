//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_977_SORTEDSQUARES_H
#define LEETCODE_977_SORTEDSQUARES_H

#include "solution.h"

class SortedSquares : public solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int idx1 = 0, idx2 = 0;
        for (; idx2 < nums.size(); ++idx2) {
            if (nums[idx2] >= 0)
                break;
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        idx1 = idx2 - 1;
        int idx = 0;
        while(idx1 >= 0 && idx2 < nums.size()) {
            if (nums[idx1] <= nums[idx2]) {
                res[idx] = nums[idx1];
                --idx1;
            } else {
                res[idx] = nums[idx2];
                ++idx2;
            }
            ++idx;
        }
        while(idx1 >= 0) {
            res[idx] = nums[idx1];
            ++idx;
            --idx1;
        }
        while(idx2 < nums.size()) {
            res[idx] = nums[idx2];
            ++idx;
            ++idx2;
        }
        return res;
    }
};

#endif //LEETCODE_977_SORTEDSQUARES_H
