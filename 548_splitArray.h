//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_548_SPLITARRAY_H
#define LEETCODE_548_SPLITARRAY_H

#include "solution.h"

class SplitArray : public solution {
public:
    bool splitArray(vector<int> &nums) {
        map<int, vector<int>> mm;
        int len = nums.size();
        vector<int> sum(len, 0);
        sum[0] = nums[0];
        mm.insert({nums[0], {0}});
        int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i = 1; i < len; ++i) {
            sum[i] = sum[i - 1] + nums[i];
            auto iter = mm.find(nums[i]);
            if (iter != mm.end()) {
                iter->second.push_back(i);
            } else {
                mm.insert({nums[i], {i}});
            }
        }
        for (int i = 1; i < len; ++i) {
            sum0 = sum[i - 1];
            for (int j = i + 2; j < len; ++j) {
                sum1 = sum[j - 1] - sum[i];
                if (sum1 != sum0) continue;
                int valk = sum[len - 1] - sum0 * 4 - nums[i] - nums[j];
                auto iter = mm.find(valk);
                if (iter != mm.end()) {
                    auto &tmpV = iter->second;
                    for (auto k : tmpV) {
                        if (k < j + 2 || k >= len - 1)
                            continue;
                        else {
                            sum2 = sum[k - 1] - sum[j];
                            if (sum2 == sum1)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    void check() {
        vector<int> nums{1, 2, 1, 2, 1, 2, 1};
        int res = splitArray(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_548_SPLITARRAY_H
