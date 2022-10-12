//
// Created by 王柯 on 10/12/22.
//

#ifndef LEETCODE_18_FOURSUM_H
#define LEETCODE_18_FOURSUM_H

#include "solution.h"

class FourSum : public solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> ss;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i0 = 0; i0 < len; ++i0) {
            for (int i1 = i0 + 1; i1 < len; ++i1) {
                int l = i1 + 1, r = len - 1;
                long long sum = nums[i0] + nums[i1];
                while (l < r) {
                    long long tmp = sum + nums[l] + nums[r];
                    if (tmp == target) {
                        vector<int> tmpRes{nums[i0], nums[i1], nums[l], nums[r]};
                        if (ss.find(tmpRes) == ss.end()) {
                            res.emplace_back(tmpRes);
                            ss.insert(tmpRes);
                        }
                        ++l;
                        --r;
                    } else if (tmp < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return res;
    }

    void check() {

    }
};


#endif //LEETCODE_18_FOURSUM_H
