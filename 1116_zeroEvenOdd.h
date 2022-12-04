//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1116_ZEROEVENODD_H
#define LEETCODE_1116_ZEROEVENODD_H

#include "solution.h"

class ZeroEvenOdd {
private:
    int n;
    bool flag;
    mutex zeroRound, evenRound, oddRound;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        flag = false;
        evenRound.lock();
        oddRound.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            zeroRound.lock();
            printNumber(0);
            if (flag) {
                evenRound.unlock();
            } else {
                oddRound.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            evenRound.lock();
            printNumber(i);
            flag = false;
            zeroRound.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            oddRound.lock();
            printNumber(i);
            flag = true;
            zeroRound.unlock();
        }
    }
};

#endif //LEETCODE_1116_ZEROEVENODD_H
