//
// Created by 王柯 on 10/11/22.
//

#ifndef LEETCODE_295_MEDIANFINDER_H
#define LEETCODE_295_MEDIANFINDER_H

#include "solution.h"

class MedianFinder {
public:
    struct lessCmp {
        bool operator() (const int a, const int b) {
            return a < b;
        }
    };
    struct largeCmp {
        bool operator() (const int a, const int b) {
            return a > b;
        }
    };

    int cnt;
    priority_queue<int, vector<int>, lessCmp> lHalf;
    priority_queue<int, vector<int>, largeCmp> rHalf;

    MedianFinder() {
        cnt = 0;
    }

    void addNum(int num) {
        if (cnt == 0) {
            lHalf.push(num);
        } else if (cnt % 2) {
            if (num < lHalf.top()) {
                rHalf.push(lHalf.top());
                lHalf.pop();
                lHalf.push(num);
            } else {
                rHalf.push(num);
            }
        } else {
            if (num > rHalf.top()) {
                lHalf.push(rHalf.top());
                rHalf.pop();
                rHalf.push(num);
            } else {
                lHalf.push(num);
            }
        }
        ++cnt;
    }

    double findMedian() {
        if (cnt % 2) {
            return lHalf.top();
        } else {
            return ((double)lHalf.top() + rHalf.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //LEETCODE_295_MEDIANFINDER_H
