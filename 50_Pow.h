//
// Created by Admin on 9/29/2024.
//

#ifndef LEETCODE_50_POW_H
#define LEETCODE_50_POW_H

#include "solution.h"

class Pow : public solution {
public:
    double myPow(double x, int n) {
        double res = 1;

        if (n < 0) {
            x = 1 / x;
        }

        long power = labs(n);
        while(power != 0) {
            if (power % 2 == 1) {
                res *= x;
            }
            x *= x;
            power /= 2;
        }

        return res;
    }

    void check() {
        cout << myPow(2.0, -2147483648) << endl;
    }
};

#endif //LEETCODE_50_POW_H
