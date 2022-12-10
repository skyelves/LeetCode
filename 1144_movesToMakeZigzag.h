//
// Created by 王柯 on 12/9/22.
//

#ifndef LEETCODE_1144_MOVESTOMAKEZIGZAG_H
#define LEETCODE_1144_MOVESTOMAKEZIGZAG_H

#include "solution.h"

class MovesToMakeZigzag : public solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {
        int res = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int left = i - 1, right = i + 1, tmp1 = INT_MAX, tmp2 = INT_MAX;
            if (left >= 0 && nums[left] <= nums[i])
                tmp1 =  nums[i] - nums[left] + 1;
            if (right < nums.size() && nums[right] <= nums[i])
                tmp2 = nums[i] - nums[right] + 1;
            if (tmp1 != INT_MAX && tmp2 != INT_MAX)
                sum += max(tmp1, tmp2);
            else if (tmp1 != INT_MAX)
                sum += tmp1;
            else if (tmp2 != INT_MAX)
                sum += tmp2;
        }
        res = min(res, sum);
        sum = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            int left = i - 1, right = i + 1, tmp1 = INT_MAX, tmp2 = INT_MAX;
            if (left >= 0 && nums[left] <= nums[i])
                tmp1 = nums[i] - nums[left] + 1;
            if (right < nums.size() && nums[right] <= nums[i])
                tmp2 = nums[i] - nums[right] + 1;
            if (tmp1 != INT_MAX && tmp2 != INT_MAX)
                sum += max(tmp1, tmp2);
            else if (tmp1 != INT_MAX)
                sum += tmp1;
            else if (tmp2 != INT_MAX)
                sum += tmp2;
        }
        res = min(res, sum);

        return res;
    }

    void check() {
        vector<int> nums{2, 7, 10, 9, 8, 9};
        int res = movesToMakeZigzag(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_1144_MOVESTOMAKEZIGZAG_H
