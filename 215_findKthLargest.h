//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_215_FINDKTHLARGEST_H
#define LEETCODE_215_FINDKTHLARGEST_H

#include "solution.h"

class FindKthLargest : public solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> qq;
        for (int i = 0; i < k; ++i) {
            qq.push(nums[i]);
        }
        for (int i = k; i < n; ++i) {
            int tmpT = qq.top();
            if (nums[i] > tmpT) {
                qq.pop();
                qq.push(nums[i]);
            }
        }
        return qq.top();
    }

    void check() {

    }
};

#endif //LEETCODE_215_FINDKTHLARGEST_H
