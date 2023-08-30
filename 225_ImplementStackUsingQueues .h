//
// Created by 王柯 on 8/28/23.
//

#ifndef LEETCODE_225_IMPLEMENTSTACKUSINGQUEUES_H
#define LEETCODE_225_IMPLEMENTSTACKUSINGQUEUES_H

#include "solution.h"

class MyStack : public solution {
public:
    queue<int> qq;

    MyStack() {

    }

    void push(int x) {
        int size = qq.size();
        qq.push(x);
        for (int i = 0; i < size; ++i) {
            int tmp = qq.front();
            qq.pop();
            qq.push(tmp);
        }
    }

    int pop() {
        int res = qq.front();
        qq.pop();
        return res;
    }

    int top() {
        return qq.front();
    }

    bool empty() {
        return qq.empty();
    }
};

#endif //LEETCODE_225_IMPLEMENTSTACKUSINGQUEUES_H
