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
        vector<int> dp0(len, 0), dp1(len, 0);
        dp0[0] = 0;
        dp1[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp0[i] = max(dp0[i - 1], dp1[i - 1]);
            dp1[i] = dp0[i - 1] + nums[i];
        }
        return max(dp0[len - 1], dp1[len - 1]);
    }

    void check() {
        int res = 0;
        vector<int> nums{1, 2, 3, 1};
        res = rob(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_198_HOUSEROBBER_H
