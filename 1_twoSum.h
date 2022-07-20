//
// Created by 王柯 on 4/6/22.
//

#ifndef LEETCODE_1_TWOSUM_H
#define LEETCODE_1_TWOSUM_H

#include "solution.h"

using namespace std;

class TwoSum : public solution{
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        int len = nums.size();
        auto new_nums = nums;
        sort(new_nums.begin(), new_nums.end());
        for (auto i = new_nums.begin(); i != new_nums.end(); ++i) {
            int curr_num = *i;
            int remainder = target - curr_num;
            auto idx = lower_bound(i, new_nums.end(), remainder);
            if (idx != new_nums.end() && *idx == remainder) {
                for (int j = 0; j < len; ++j) {
                    if (nums[j] == curr_num || nums[j] == remainder) {
                        res.push_back(j);
                    }
                }
                return res;
            }
        }
        return res;
    }

    void check() {
        vector<int> nums = {2, 13, 11, 15};
        int target = 13;
        auto res = twoSum(nums, target);
        cout << res[0] << ", " << res[1] << endl;
    }
};

#endif //LEETCODE_1_TWOSUM_H
