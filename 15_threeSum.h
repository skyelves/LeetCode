//
// Created by 王柯 on 10/12/22.
//

#ifndef LEETCODE_15_THREESUM_H
#define LEETCODE_15_THREESUM_H

#include "solution.h"

class ThreeSum : public solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        set<vector<int>> ss;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int l = i + 1, r = len - 1;
            while (l < r) {
                int tmp = nums[i] + nums[l] + nums[r];
                if (tmp == 0) {
                    vector<int> tmpRes{nums[i], nums[l], nums[r]};
                    if (ss.find(tmpRes) == ss.end()) {
                        ss.insert(tmpRes);
                        res.emplace_back(tmpRes);
                    }
                    ++l;
                    --r;
                } else if (tmp > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_15_THREESUM_H
