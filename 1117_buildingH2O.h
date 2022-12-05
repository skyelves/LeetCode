//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1117_BUILDINGH2O_H
#define LEETCODE_1117_BUILDINGH2O_H

#include "solution.h"

class H2O {
public:
    int hCnt, oCnt;
    mutex m1, m2;

    H2O() {
        hCnt = 0;
        oCnt = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        m1.lock();
        cout << "H";
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++hCnt;
        if (hCnt == 2 && oCnt == 1) {
            hCnt = oCnt = 0;
            m1.unlock();
            m2.unlock();
        } else if (hCnt == 1) {
            m1.unlock();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        m2.lock();
        cout << "O";
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++oCnt;
        if (hCnt == 2) {
            hCnt = oCnt = 0;
            m1.unlock();
            m2.unlock();
        }
    }
};

#endif //LEETCODE_1117_BUILDINGH2O_H
