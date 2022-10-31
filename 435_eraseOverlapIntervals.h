//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_435_ERASEOVERLAPINTERVALS_H
#define LEETCODE_435_ERASEOVERLAPINTERVALS_H

#include "solution.h"

class EraseOverlapIntervals : public solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        int endTime = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < endTime) {
                endTime = min(endTime, intervals[i][1]);
                ++res;
            } else {
                endTime = intervals[i][1];
            }
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_435_ERASEOVERLAPINTERVALS_H
