//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_1381_CUSTOMSTACK_H
#define LEETCODE_1381_CUSTOMSTACK_H

#include "solution.h"

class CustomStack {
public:
    int capacity = 0;
    int cnt = 0;
    vector<int> ss;

    CustomStack(int maxSize) {
        capacity = maxSize;
        cnt = 0;
        ss.resize(maxSize);
    }

    void push(int x) {
        if (cnt < capacity) {
            ss[cnt++] = x;
        }
    }

    int pop() {
        if (cnt > 0)
            return ss[--cnt];
        return -1;
    }

    void increment(int k, int val) {
        k = min(k, cnt);
        for (int i = 0; i < k; ++i) {
            ss[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

#endif //LEETCODE_1381_CUSTOMSTACK_H
