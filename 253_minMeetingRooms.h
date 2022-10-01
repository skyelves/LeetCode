//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_253_MINMEETINGROOMS_H
#define LEETCODE_253_MINMEETINGROOMS_H

#include "solution.h"

class MinMeetingRooms : public solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        int res = 0;
        vector<int> startTime, endTime;
        for (int i = 0; i < intervals.size(); ++i) {
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int i = 0, j = 0, cnt = 0;
        while (i < startTime.size()) {
            if (startTime[i] < endTime[j]) {
                i++;
                cnt++;
                res = max(res, cnt);
            } else {
                cnt--;
                j++;
            }
        }
        return res;
    }

    void check() {
        vector<vector<int>> intervals{{0,  30},
                                      {5,  10},
                                      {15, 20}};
        int res = minMeetingRooms(intervals);
        cout << res << endl;
    }
};

#endif //LEETCODE_253_MINMEETINGROOMS_H
