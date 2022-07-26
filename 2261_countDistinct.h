//
// Created by 王柯 on 7/25/22.
//

#ifndef LEETCODE_2261_COUNTDISTINCT_H
#define LEETCODE_2261_COUNTDISTINCT_H

#include "solution.h"

class CountDistinct : public solution {
public:
    bool divisible[200] = {0};

    int countDistinct(vector<int> &nums, int k, int p) {
        int res = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] % p == 0)
                divisible[i] = true;
        }
        for (int l = 1; l <= len; ++l) {
            set<vector<int> > existing;
            for (int i = 0; i <= len - l; ++i) {
                int tmp_k = 0;
                for (int j = 0; j < l; ++j) {
                    if (divisible[i + j]) {
                        tmp_k++;
                    }
                }
                vector<int> tmp(nums.begin() + i, nums.begin() + i + l);
                if (tmp_k <= k && existing.find(tmp) == existing.end())
                    res++;
                existing.insert(tmp);
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2261_COUNTDISTINCT_H
