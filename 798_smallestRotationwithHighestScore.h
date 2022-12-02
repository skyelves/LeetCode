//
// Created by 王柯 on 12/1/22.
//

#ifndef LEETCODE_798_SMALLESTROTATIONWITHHIGHESTSCORE_H
#define LEETCODE_798_SMALLESTROTATIONWITHHIGHESTSCORE_H

#include "solution.h"

class BestRotation : public solution {
public:
    int bestRotation(vector<int> &nums) {
        int res = 0;
        int len = nums.size();
        vector<int> intervals(len + 1, 0);
        for (int i = 0; i < len; ++i) {
            if (nums[i] < len) {
                // [nums[i] + 1, len - 1]
                if (nums[i] > i) {
                    int left = i + 1;
                    int right = i + len - nums[i];
                    ++intervals[left];
                    --intervals[right + 1];
                } else {
                    // i >= nums[i]
                    // rotate [0, i - nums[i]], [i + 1, len - 1]
                    ++intervals[0];
                    --intervals[i - nums[i] + 1];
                    ++intervals[i + 1];
                    --intervals[len];
                }
            }
        }

        int tmp = 0, maxCnt = 0;
        for (int i = 0; i < len; ++i) {
            tmp += intervals[i];
            if (tmp > maxCnt) {
                maxCnt = tmp;
                res = i;
            }
        }

        return res;
    }

    void check() {
        vector<int> nums{2, 3, 1, 4, 0};
        int res = bestRotation(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_798_SMALLESTROTATIONWITHHIGHESTSCORE_H
