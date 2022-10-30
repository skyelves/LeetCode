//
// Created by 王柯 on 10/29/22.
//

#ifndef LEETCODE_69_SQRT_H
#define LEETCODE_69_SQRT_H

#include "solution.h"

class MySqrt : public solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int l = 0, r = 1 << 16;
        while(l < r) {
            long long mid = (l + r) / 2;
            long long tmp = mid * mid;
            long long tmpNext = (mid + 1) * (mid + 1);
            if (tmp == x || (tmp < x && tmpNext > x)) {
                return mid;
            } else if (tmp < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    void check() {
        int x = 8;
        int res = mySqrt(x);
        cout << res << endl;
    }
};

#endif //LEETCODE_69_SQRT_H
