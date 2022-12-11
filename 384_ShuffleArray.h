//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_384_SHUFFLEARRAY_H
#define LEETCODE_384_SHUFFLEARRAY_H

#include "solution.h"

class Solution {
    vector<int> origin;
    vector<int> _nums;
public:
    Solution(vector<int>& nums) {
        _nums = nums;
        origin = nums;
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        int n = _nums.size();
        for (int i = n; i > 0; --i) {
            int idx = rand() % i;
            swap(_nums[idx], _nums[i - 1]);
        }
        return _nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

#endif //LEETCODE_384_SHUFFLEARRAY_H
