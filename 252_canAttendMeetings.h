//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_252_CANATTENDMEETINGS_H
#define LEETCODE_252_CANATTENDMEETINGS_H

#include "solution.h"

class CanAttendMeetings : public solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.size() < 2)
            return true;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];});
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0])
                return false;
        }
        return true;
    }

    void check() {

    }
};

#endif //LEETCODE_252_CANATTENDMEETINGS_H
