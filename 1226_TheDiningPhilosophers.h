//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1226_THEDININGPHILOSOPHERS_H
#define LEETCODE_1226_THEDININGPHILOSOPHERS_H

#include "solution.h"

class DiningPhilosophers {
public:
    mutex m[5];
    mutex mm;
    condition_variable cv;
    int picked;

    DiningPhilosophers() {
        picked = 0;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int cnt = 0;
        int left = (philosopher + 4) % 5;
        int right = philosopher;
        unique_lock<mutex> lock1(mm);
        cv.wait(lock1, [=]() { return picked < 4; });
        m[left].lock();
        ++picked;
        pickLeftFork();
        m[right].lock();
        ++picked;
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        picked -= 2;
        m[left].unlock();
        m[right].unlock();
        cv.notify_all();
    }
};

#endif //LEETCODE_1226_THEDININGPHILOSOPHERS_H
