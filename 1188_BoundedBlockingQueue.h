//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1188_BOUNDEDBLOCKINGQUEUE_H
#define LEETCODE_1188_BOUNDEDBLOCKINGQUEUE_H

#include "solution.h"

class BoundedBlockingQueue {
public:
    int c;
    mutex m1;
    condition_variable cv;
    queue<int> qq;

    BoundedBlockingQueue(int capacity) {
        c = capacity;
    }

    void enqueue(int element) {
        unique_lock<mutex> lock1(m1);
        cv.wait(lock1, [=](){return qq.size() < c;});
        qq.push(element);
        cv.notify_all();
    }

    int dequeue() {
        unique_lock<mutex> lock1(m1);
        cv.wait(lock1, [=](){return qq.size() > 0;});
        int res = qq.front();
        qq.pop();
        cv.notify_all();
        return res;
    }

    int size() {
        return qq.size();
    }
};

#endif //LEETCODE_1188_BOUNDEDBLOCKINGQUEUE_H
