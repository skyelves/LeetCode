//
// Created by 王柯 on 9/9/22.
//

#ifndef LEETCODE_198_HOUSEROBBER_H
#define LEETCODE_198_HOUSEROBBER_H

#include "solution.h"

class Rob : public solution {
public:
    int rob(vector<int> &nums) {
        int res = 0;
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);
        int *dp0 = new int[len];
        int *dp1 = new int[len];
        dp0[0] = 0;
        dp0[1] = nums[0];
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        for (int i = 2; i < len; ++i) {
            dp0[i] = max(dp1[i - 1], dp0[i - 1]);
            dp1[i] = nums[i] + dp0[i - 1];
        }
        return max(dp0[len - 1], dp1[len - 1]);
    }

    void check() {
        int res = 0;
        vector<int> nums{1,2,3,1};
        res = rob(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_198_HOUSEROBBER_H
