//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_259_THREESUMSMALLER_H
#define LEETCODE_259_THREESUMSMALLER_H

#include "solution.h"

class ThreeSumSmaller : public solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int lo = i + 1, hi = n - 1;
            int tmp = nums[i] + nums[lo] - target;
            while (lo < hi) {
                if (nums[i] + nums[lo] + nums[hi] - target >= 0) {
                    hi--;
                } else {
                    res += (hi - lo);
                    lo++;
                }
            }
        }
        return res;
    }

    void check() {
        vector<int> nums{-2, 0, 1, 3};
        int target = 2;
        int res = threeSumSmaller(nums, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_259_THREESUMSMALLER_H
