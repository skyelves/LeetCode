//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1195_FIZZBUZZMULTITHREADED_H
#define LEETCODE_1195_FIZZBUZZMULTITHREADED_H

#include "solution.h"

class FizzBuzz {
private:
    int n;
    int cnt;
    mutex m1;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        cnt = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (cnt <= n) {
            unique_lock<mutex> lock1(m1);
            cv.wait(lock1, [=]() { return ((cnt % 3 == 0) && (cnt % 5 != 0)) || (cnt > n); });
            if (cnt > n)
                break;
            ++cnt;
            printFizz();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (cnt <= n) {
            unique_lock<mutex> lock1(m1);
            cv.wait(lock1, [=]() { return ((cnt % 3 != 0) && (cnt % 5 == 0)) || (cnt > n); });
            if (cnt > n)
                break;
            ++cnt;
            printBuzz();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (cnt <= n) {
            unique_lock<mutex> lock1(m1);
            cv.wait(lock1, [=]() { return ((cnt % 3 == 0) && (cnt % 5 == 0)) || (cnt > n); });
            if (cnt > n)
                break;
            ++cnt;
            printFizzBuzz();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (cnt <= n) {
            unique_lock<mutex> lock1(m1);
            cv.wait(lock1, [=]() { return ((cnt % 3 != 0) && (cnt % 5 != 0)) || (cnt > n); });
            if (cnt > n)
                break;
            printNumber(cnt);
            ++cnt;
            cv.notify_all();
        }
    }
};

#endif //LEETCODE_1195_FIZZBUZZMULTITHREADED_H
