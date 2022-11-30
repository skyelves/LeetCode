//
// Created by 王柯 on 11/29/22.
//

#ifndef LEETCODE_362_HITCOUNTER_H
#define LEETCODE_362_HITCOUNTER_H

#include "solution.h"

class HitCounter {
public:
    queue<pair<int, int>> qq;
    int hits = 0;

    HitCounter() {

    }

    void hit(int timestamp) {
        if (!qq.empty() && qq.back().first == timestamp) {
            qq.back().second += 1;
        } else
            qq.push({timestamp, 1});
        ++hits;
    }

    int getHits(int timestamp) {
        int startTime = timestamp - 300 + 1;
        while (!qq.empty() && qq.front().first < startTime) {
            hits -= qq.front().second;
            qq.pop();
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

#endif //LEETCODE_362_HITCOUNTER_H
