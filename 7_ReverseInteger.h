//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_7_REVERSEINTEGER_H
#define LEETCODE_7_REVERSEINTEGER_H

#include "solution.h"

class ReverseInteger : public solution {
public:
    int reverse(int x) {
        int res = 0;
        int ub = INT_MAX / 10, lb = INT_MIN / 10;
        while (x != 0) {
            int tmp = x % 10;
            x /= 10;
            if (res > ub || res < lb)
                return 0;
            else if (res == ub) {
                if (tmp > 7)
                    return 0;
            } else if (res == lb) {
                if (tmp < -8)
                    return 0;
            }
            res *= 10;
            res += tmp;
        }
        return res;
    }

    void check() {
        int res = reverse(-17);
        cout << res << endl;
    }
};

#endif //LEETCODE_7_REVERSEINTEGER_H
