//
// Created by 王柯 on 11/2/22.
//

#ifndef LEETCODE_47_PERMUTATIONS2_H
#define LEETCODE_47_PERMUTATIONS2_H

#include "solution.h"

class PermuteUnique : public solution {
public:
    set<vector<int>> ss;

    void dfs(vector<int> &nums, int cnt, vector<int> curr, vector<bool> &used, vector<vector<int>> &res) {
        if (ss.find(curr) == ss.end()) {
            ss.insert(curr);
        } else {
            return;
        }
        if (cnt == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                vector<int> newCurr = curr;
                newCurr.push_back(nums[i]);
                used[i] = true;
                dfs(nums, cnt + 1, newCurr, used, res);
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        dfs(nums, 0, {}, used, res);
        return res;
    }

    void check() {
        vector<int> nums{1, 1, 2};
        auto res = permuteUnique(nums);
        for (auto &i : res) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_47_PERMUTATIONS2_H
