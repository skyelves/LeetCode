//
// Created by 王柯 on 12/30/22.
//

#ifndef LEETCODE_704_BINARYSEARCH_H
#define LEETCODE_704_BINARYSEARCH_H

#include "solution.h"

class BinarySearch : public solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

#endif //LEETCODE_704_BINARYSEARCH_H
