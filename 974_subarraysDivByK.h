//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_974_SUBARRAYSDIVBYK_H
#define LEETCODE_974_SUBARRAYSDIVBYK_H

#include "solution.h"

class SubarraysDivByK : public solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int res = 0, sum = 0;
        vector<int> sumCnt(k, 0);
        sumCnt[0] = 1;
        for (auto &i : nums) {
            sum = (sum + i) % k;
            if (sum < 0) sum += k;
            res += sumCnt[sum];
            ++sumCnt[sum];
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_974_SUBARRAYSDIVBYK_H
