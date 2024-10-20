//
// Created by Ke Wang on 10/20/24.
//

#ifndef INC_162_FINDPEAKELEMENT_H
#define INC_162_FINDPEAKELEMENT_H

#include "solution.h"

class FindPeakElement : public solution {
    int findPeakElement(vector<int>& nums) {
        return findPeak(0, nums.size() - 1, nums);
    }

    int findPeak(int i, int j, vector<int> &nums) {
        if (i == j) {
            return i;
        } else if (i + 1 == j) {
            return nums[i] > nums[j] ? i : j;
        }
        int mid = (i + j) / 2;
        if (nums[mid] < nums[mid + 1]) {
            return findPeak(mid + 1, j, nums);
        } else {
            return findPeak(i, mid, nums);
        }
    }
};

#endif //INC_162_FINDPEAKELEMENT_H
