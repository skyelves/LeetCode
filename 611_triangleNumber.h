//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_611_TRIANGLENUMBER_H
#define LEETCODE_611_TRIANGLENUMBER_H

#include "solution.h"

class TriangleNumber : public solution {
public:
    int triangleNumber(vector<int> &nums) {
        int len = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < len; ++j) {
                k = max(k, j + 1);
                while (k < len && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                res += (k - j - 1);
            }
        }

        return res;
    }

    void check() {
        vector<int> nums{4, 2, 3, 4};
        int res = triangleNumber(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_611_TRIANGLENUMBER_H
