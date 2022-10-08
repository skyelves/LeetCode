//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_560_SUBARRAYSUM_H
#define LEETCODE_560_SUBARRAYSUM_H

#include "solution.h"

class SubarraySum : public solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> sumCnt;
        sumCnt[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto iter = sumCnt.find(sum - k);
            if (iter != sumCnt.end()) {
                res += iter->second;
            }
            sumCnt[sum]++;
        }
        return res;
    }

    void check() {
        vector<int> nums{1, 1, 1};
        int k = 2;
        int res = subarraySum(nums, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_560_SUBARRAYSUM_H
