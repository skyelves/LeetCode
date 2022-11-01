//
// Created by 王柯 on 10/31/22.
//

#ifndef LEETCODE_46_PERMUTATION_H
#define LEETCODE_46_PERMUTATION_H

#include "solution.h"

class Permute : public solution {
public:
    void dfs(vector<int> &nums, set<int> &used, vector<int> &tmpRes, vector<vector<int>> &res) {
        if (used.size() == nums.size()) {
            res.push_back(tmpRes);
            return;
        }
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);
                tmpRes.push_back(nums[i]);
                dfs(nums, used, tmpRes, res);
                used.erase(nums[i]);
                tmpRes.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        set<int> used;
        vector<vector<int>> res;
        vector<int> tmpRes;
        dfs(nums, used, tmpRes, res);
        return res;
    }

    void check() {
        vector<int> nums{1};
        auto res = permute(nums);
        for (auto &i : res) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_46_PERMUTATION_H
