//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_81_ROTATEDSORTEDARRAY2_H
#define LEETCODE_81_ROTATEDSORTEDARRAY2_H

#include "solution.h"

class rotatedSortedArray2 : public solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int midValue = nums[mid];
            if (midValue == target || nums[l] == target || nums[r] == target)
                return true;
            if (target > nums[l] && target < midValue) {
                r = mid - 1;
            } else if (target > midValue && target < nums[r]) {
                l = mid + 1;
            } else {
                ++l;
                --r;
            }
        }
        return false;
    }

    void check() {

    }
};

#endif //LEETCODE_81_ROTATEDSORTEDARRAY2_H
