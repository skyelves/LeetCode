//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_154_FINDMINIMUMINROTATEDSORTEDARRAY2_H
#define LEETCODE_154_FINDMINIMUMINROTATEDSORTEDARRAY2_H

#include "solution.h"

class FindMinimuminRotatedSortedArray2 : public solution {
public:
    int findMin(vector<int> &nums) {
        int res = INT_MAX;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int midValue = nums[mid];
            res = min(res, midValue);
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                return res;
            } else if (nums[l] > nums[r]) {
                if (midValue >= nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (midValue > nums[l]) {
                    l = mid + 1;
                } else if (midValue < nums[l]) {
                    r = mid - 1;
                } else {
                    res = min(res, nums[l]);
                    ++l;
                    --r;
                }
            }
        }
        return res;
    }

    void check() {
        vector<int> nums{1, 2, 0, 0, 1};
        int res = findMin(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_154_FINDMINIMUMINROTATEDSORTEDARRAY2_H
