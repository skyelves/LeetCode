//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_153_FINDMINROTATED_H
#define LEETCODE_153_FINDMINROTATED_H

#include "solution.h"

class FindMin : public solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, res = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            int midValue = nums[mid];
            res = min(res, midValue);
            if (midValue < nums[l] || nums[l] < nums[r]) {
                r = mid - 1;
            } else {
                // midValue >= nums[l]
                l = mid + 1;
            }
        }
        return res;
    }

    void check() {
        vector<int> nums{1, 2, 3};
        int res = findMin(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_153_FINDMINROTATED_H
