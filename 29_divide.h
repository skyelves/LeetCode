//
// Created by 王柯 on 9/5/22.
//

#ifndef LEETCODE_29_DIVIDE_H
#define LEETCODE_29_DIVIDE_H

#include "solution.h"

class Divide : public solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if (dividend == 0) return 0;
        if (dividend == INT_MIN) {
            if (divisor == 1)
                return INT_MIN;
            else if (divisor == -1)
                return INT_MAX;
            else if (divisor == INT_MIN)
                return 1;
        } else if (divisor == INT_MIN) {
            return 0;
        }
        bool sign = (dividend >> 31) == (divisor >> 31);
        divisor = abs(divisor);
        if (dividend > 0) {
            while (dividend >= divisor) {
                for (int i = 0; i < 32; ++i) {
                    int tmp = divisor << i;
                    if (tmp < 0 || tmp > dividend) {
                        dividend -= divisor << (i - 1);
                        res += 1 << (i - 1);
                        break;
                    } else if (tmp == dividend) {
                        dividend = 0;
                        res += 1 << i;
                        break;
                    }
                }
            }
        } else {
            while (dividend + divisor <= 0) {
                for (int i = 0; i < 32; ++i) {
                    int tmp = divisor << i;
                    if ( tmp < 0 || tmp + dividend > 0) {
                        dividend += divisor << (i - 1);
                        res += 1 << (i - 1);
                        break;
                    } else if (tmp + dividend == 0) {
                        dividend = 0;
                        res += 1 << i;
                        break;
                    }
                }
            }
        }
        return sign ? res : -res;
    }

    void check() {
        int a = INT_MIN, b = 2;
        int res = divide(a, b);
        cout << res << endl;
    }
};

#endif //LEETCODE_29_DIVIDE_H