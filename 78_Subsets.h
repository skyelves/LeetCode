//
// Created by Admin on 10/1/2024.
//

#ifndef LEETCODE_78_SUBSETS_H
#define LEETCODE_78_SUBSETS_H

#include "solution.h"

class Subsets : public solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        vector<vector<int>> res;
        int lastNum = nums[nums.size() - 1];
        nums.pop_back();
        vector<vector<int>> nextRes = subsets(nums);
        for (auto &i : nextRes) {
            res.push_back(i);
            i.push_back(lastNum);
            res.push_back(i);
        }
        return res;
    }
};

#endif //LEETCODE_78_SUBSETS_H
