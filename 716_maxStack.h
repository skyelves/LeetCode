//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_716_MAXSTACK_H
#define LEETCODE_716_MAXSTACK_H

#include "solution.h"

class MaxStack {
public:
    struct cmp {
    public:
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        }
    };

    stack<pair<int, int>> ss; // <num, id>
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // <num, id>
    unordered_set<int> removed;
    int idCnt = 0;

    MaxStack() {

    }

    void push(int x) {
        ss.push({x, idCnt});
        pq.push({x, idCnt});
        ++idCnt;
    }

    int pop() {
        auto tmp = ss.top();
        while (removed.find(tmp.second) != removed.end()) {
            removed.erase(tmp.second);
            ss.pop();
            tmp = ss.top();
        }
        ss.pop();
        removed.insert(tmp.second);
        return tmp.first;
    }

    int top() {
        auto tmp = ss.top();
        while (removed.find(tmp.second) != removed.end()) {
            removed.erase(tmp.second);
            ss.pop();
            tmp = ss.top();
        }
        return tmp.first;
    }

    int peekMax() {
        auto tmp = pq.top();
        while (removed.find(tmp.second) != removed.end()) {
            removed.erase(tmp.second);
            pq.pop();
            tmp = pq.top();
        }
        return tmp.first;
    }

    int popMax() {
        auto tmp = pq.top();
        while (removed.find(tmp.second) != removed.end()) {
            removed.erase(tmp.second);
            pq.pop();
            tmp = pq.top();
        }
        pq.pop();
        removed.insert(tmp.second);
        return tmp.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

#endif //LEETCODE_716_MAXSTACK_H
