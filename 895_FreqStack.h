//
// Created by 王柯 on 12/3/22.
//

#ifndef LEETCODE_895_FREQSTACK_H
#define LEETCODE_895_FREQSTACK_H

#include "solution.h"

class FreqStack {
public:
    map<int, list<int>, greater<int>> mm;
    map<int, int> cnt;

    FreqStack() {

    }

    void push(int val) {
        int c = ++cnt[val];
        mm[c].push_back(val);
    }

    int pop() {
        auto iter = mm.begin();
        int res = iter->second.back();
        iter->second.pop_back();
        if (iter->second.size() == 0) {
            mm.erase(iter);
        }
        --cnt[res];
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

#endif //LEETCODE_895_FREQSTACK_H
