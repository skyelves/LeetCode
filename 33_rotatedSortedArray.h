//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_33_ROTATEDSORTEDARRAY_H
#define LEETCODE_33_ROTATEDSORTEDARRAY_H

#include "solution.h"

class RotatedSortedArray : public solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int midValue = nums[mid];
            if (midValue == target)
                return mid;
            if (midValue >= nums[l]) {
                if (target >= nums[l] && target < midValue) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // midValue < nums[l]
                if (target > midValue && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }

    void check() {
        vector<int> nums{5, 1, 2, 3, 4};
        int target = 1;
        int res = search(nums, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_33_ROTATEDSORTEDARRAY_H
