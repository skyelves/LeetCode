//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_759_EMPLOYEEFREETIME_H
#define LEETCODE_759_EMPLOYEEFREETIME_H

#include "solution.h"

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class EmployeeFreeTime : public solution {
public:
    class Interval {
    public:
        int start;
        int end;

        Interval() {}

        Interval(int _start, int _end) {
            start = _start;
            end = _end;
        }
    };

    int cnt;

    vector<int> findStart(vector<vector<Interval>> &schedule) {
        int s = INT_MAX, e = INT_MAX, idx = -1;
        for (int i = 0; i < schedule.size(); ++i) {
            if (schedule[i].size() > 0 && schedule[i][0].start < s) {
                s = schedule[i][0].start;
                e = schedule[i][0].end;
                idx = i;
            }
        }
        schedule[idx].erase(schedule[idx].begin());
        if (schedule[idx].size() == 0)
            ++cnt;
        return {s, e};
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res, workTime;
        cnt = 0;
        int num = schedule.size();
        while (cnt < num) {
            auto fs = findStart(schedule);
            int s = fs[0], e = fs[1];
            bool flag = false;
            do {
                flag = false;
                for (int i = 0; i < schedule.size(); ++i) {
                    while (schedule[i].size() > 0 && schedule[i][0].start <= e) {
                        flag = true;
                        e = max(e, schedule[i][0].end);
                        schedule[i].erase(schedule[i].begin());
                        if (schedule[i].size() == 0)
                            ++cnt;
                    }
                }
            } while (flag);
            workTime.push_back(Interval(s, e));
        }
        int e = workTime[0].end;
        for (int i = 1; i < workTime.size(); ++i) {
            res.push_back({e, workTime[i].start});
            e = workTime[i].end;
        }

        return res;
    }

    void check() {
        vector<vector<Interval>> schedule{{{7, 24}, {29, 33}, {45, 57}, {66, 69}, {94, 99}},
                                          {{6, 24}, {43, 49}, {56, 59}, {61, 75}, {80, 81}},
                                          {{5, 16}, {18, 26}, {33, 36}, {39, 57}, {65, 74}},
                                          {{9, 16}, {27, 35}, {40, 55}, {68, 71}, {78, 81}},
                                          {{0, 25}, {29, 31}, {40, 47}, {57, 87}, {91, 94}}};
        auto res = employeeFreeTime(schedule);
        for (auto &i : res)
            cout << i.start << " " << i.end << endl;
    }
};

#endif //LEETCODE_759_EMPLOYEEFREETIME_H
