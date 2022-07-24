//
// Created by 王柯 on 7/24/22.
//

#ifndef LEETCODE_2354_NUMBEROFEXCELLENTPAIRS_H
#define LEETCODE_2354_NUMBEROFEXCELLENTPAIRS_H

#include "solution.h"

class CountExcellentPairs : public solution {
public:
    int count_bits(int num) {
        int res = 0;
        while (num) {
            res += num & 1;
            num = num >> 1;
        }
        return res;
    }

    long long countExcellentPairs(vector<int> &nums, int k) {
        long long self = 0;
        long long res = 0;
        sort(nums.begin(), nums.end());
        int n = 0;
        // remove duplicate nums
        int prev = 0;
        vector<int> unique;
        for (auto i : nums) {
            if (i == prev)
                continue;
            unique.push_back(count_bits(i));
            prev = i;
            n++;
        }
        sort(unique.begin(), unique.end());
        for (auto iter = unique.begin(); iter != unique.end(); iter++) {
            int tmp = *iter;
            int residual = k - tmp - 1;
            if (tmp > residual)
                self++;
            auto ii = upper_bound(iter, unique.end(), residual);
            res += unique.end() - ii;
        }
        return res * 2 - self;
    }

    void check() {
        vector<int> nums{1, 2, 3, 1};
        long long res = countExcellentPairs(nums, 3);
        cout << res << endl;
    }
};

#endif //LEETCODE_2354_NUMBEROFEXCELLENTPAIRS_H
