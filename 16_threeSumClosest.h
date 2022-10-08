//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_16_THREESUMCLOSEST_H
#define LEETCODE_16_THREESUMCLOSEST_H

#include "solution.h"

class ThreeSumClosest : public solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int lo = i + 1, hi = nums.size() - 1;
            while(lo < hi) {
                int tmp = nums[i] + nums[lo] + nums[hi] - target;
                if (tmp < 0) {
                    lo++;
                    if (diff > -tmp) {
                        diff = -tmp;
                        res = tmp;
                    }
                } else if (tmp > 0) {
                    hi--;
                    if (diff > tmp) {
                        diff = tmp;
                        res = tmp;
                    }
                } else {
                    diff = 0;
                    res = 0;
                    break;
                }
            }
        }
        return res + target;
    }

    void check() {
        vector<int> nums{-1, 2, 1, -4};
        int target = 1;
        int res = threeSumClosest(nums, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_16_THREESUMCLOSEST_H
