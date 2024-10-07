//
// Created by Admin on 10/6/2024.
//

#ifndef LEETCODE_70_CLIMBINGSTAIRS_H
#define LEETCODE_70_CLIMBINGSTAIRS_H

#include "solution.h"

class ClimbingStairs : public solution {
private:
    vector<int> cnt;

public:
    int climbStairs(int n) {
        if (cnt.empty()) {
            cnt.resize(46, 0);
        }

        if (cnt[n] != 0) {
            return cnt[n];
        }
        if (n == 1) {
            cnt[1] = 1;
            return 1;
        } else if (n == 2) {
            cnt[2] = 2;
            return 2;
        }
        int res = climbStairs(n - 1) + climbStairs(n - 2);
        cnt[n] = res;
        return res;
    }
};

#endif //LEETCODE_70_CLIMBINGSTAIRS_H
