//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_215_FINDKTHLARGEST_H
#define LEETCODE_215_FINDKTHLARGEST_H

#include "solution.h"

class FindKthLargest : public solution {
public:
    int quickSelect(int left, int right, int k, vector<int> &nums) {
        if (left == right) {
            return left;
        }
        // partition
        int pivot = nums[left];
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] <= pivot) --j;
            if (i < j) {
                nums[i] = nums[j];
            }
            while (i < j && nums[i] >= pivot) ++i;
            if (i < j) {
                nums[j] = nums[i];
            }
        }
        nums[i] = pivot;

        if (i == k) {
            return pivot;
        } else if (i > k) {
            return quickSelect(left, i - 1, k, nums);
        } else {
            return quickSelect(i + 1, right, k, nums);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(0, nums.size() - 1, k - 1, nums);
    }

    void check() {
        vector<int> nums{3,2,1,5,6,4};
        int k = 2;
        int res = quickSelect(0, nums.size() - 1, k, nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_215_FINDKTHLARGEST_H
