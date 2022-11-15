//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_155_MINSTACK_H
#define LEETCODE_155_MINSTACK_H

#include "solution.h"

class MinStack {
public:
    stack<int> ss;
    stack<int> ms;

    MinStack() {

    }

    void push(int val) {
        ss.push(val);
        if (!ms.empty()) {
            ms.push(min(val, ms.top()));
        } else {
            ms.push(val);
        }
    }

    void pop() {
        ss.pop();
        ms.pop();
    }

    int top() {
        return ss.top();
    }

    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif //LEETCODE_155_MINSTACK_H
