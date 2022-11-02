//
// Created by 王柯 on 11/1/22.
//

#ifndef LEETCODE_622_MYCIRCULARQUEUE_H
#define LEETCODE_622_MYCIRCULARQUEUE_H

#include "solution.h"

class MyCircularQueue {
public:
    vector<int> ringBuffer;
    int start = 0, end = 0, cnt = 0, K = 0;

    MyCircularQueue(int k) {
        ringBuffer.resize(k);
        start = 0;
        end = 0;
        cnt = 0;
        K = k;
    }

    bool enQueue(int value) {
        if (cnt < K) {
            ringBuffer[end] = value;
            ++end;
            if (end == K)
                end = 0;
            ++cnt;
            return true;
        } else
            return false;
    }

    bool deQueue() {
        if (cnt > 0) {
            ++start;
            if (start == K)
                start = 0;
            --cnt;
            return true;
        } else {
            return false;
        }
    }

    int Front() {
        if (cnt == 0) return -1;
        return ringBuffer[start];
    }

    int Rear() {
        if (cnt == 0) return -1;
        if (end != 0)
            return ringBuffer[end - 1];
        else
            return ringBuffer[K - 1];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

#endif //LEETCODE_622_MYCIRCULARQUEUE_H
