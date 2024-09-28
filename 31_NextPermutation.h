//
// Created by Admin on 9/28/2024.
//

#ifndef LEETCODE_31_NEXTPERMUTATION_H
#define LEETCODE_31_NEXTPERMUTATION_H

#include "solution.h"

class NextPermutation : public solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            int j = i - 1;
            if (nums[j] < nums[i]) {
                reverse(nums.begin() + i, nums.end());
                for (int k = i; k < nums.size(); ++k) {
                    if (nums[j] < nums[k]) {
                        swap(nums[j], nums[k]);
                        return;
                    }
                }
            }
        }

        // nums is the largest permutation, return the smallest one, i.e., reverse the nums
        reverse(nums.begin(), nums.end());
    }

    void check() {
        vector<int> nums0{1,3,2};
        nextPermutation(nums0);
        for (int i : nums0) {
            cout << i << ", ";
        }
        cout << endl;

        vector<int> nums1{2,3,1};
        nextPermutation(nums1);
        for (int i : nums1) {
            cout << i << ", ";
        }
        cout << endl;

    }
};


#endif //LEETCODE_31_NEXTPERMUTATION_H
