//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_189_ROTATEARRAY_H
#define LEETCODE_189_ROTATEARRAY_H

#include "solution.h"

class RotateArray : public solution {
public:
    int gcd(int x, int y) {
        while (y) {
            x, y = y, x % y;
        }
        return x;
    }

    int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }

    void rotate(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len;
//        reverse(nums.begin(), nums.end());
//        reverse(nums.begin(), nums.begin() + k);
//        reverse(nums.begin() + k, nums.end());
        int l = lcm(len, k);
        int dis = gcd(len, k);
        for (int i = 0; i < dis; ++i) {
            int tmp2 = nums[i];
            int idx = (i + k) % len;
            while(idx != i) {
                int tmp1 = nums[idx];
                nums[idx] = tmp2;
                tmp2 = tmp1;
                idx = (idx + k) % len;
            }
            nums[idx] = tmp2;
        }
    }
};

#endif //LEETCODE_189_ROTATEARRAY_H
