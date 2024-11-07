//
// Created by Ke Wang on 11/6/24.
//

#ifndef INC_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
#define INC_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H

#include "solution.h"

class FindFirstAndLastPositionOfElementInSortedArray : public solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        return binarySearch(0, nums.size() - 1, target, nums);
    }

    vector<int> binarySearch(int left, int right, int target, vector<int> &nums) {
        if (nums[left] == target && nums[right] == target) {
            return {left, right};
        }
        if (left >= right) {
            return {-1, -1};
        }
        int mid_idx = (left + right) / 2;
        int mid = nums[mid_idx];
        if (mid < target) {
            return binarySearch(mid_idx + 1, right, target, nums);
        } else if (mid > target) {
            return binarySearch(left, mid_idx - 1, target, nums);
        } else {
            // mid == target
            vector<int> left_half = binarySearch(left, mid_idx, target, nums);
            vector<int> right_half = binarySearch(mid_idx + 1, right, target, nums);
            int res_left = left_half[0];
            int res_right = right_half[1] > -1 ? right_half[1] : mid_idx;
            return {res_left, res_right};
        }
    }
};

#endif //INC_34_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
