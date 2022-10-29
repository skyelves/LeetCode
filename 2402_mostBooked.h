//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_2402_MOSTBOOKED_H
#define LEETCODE_2402_MOSTBOOKED_H

#include "solution.h"

class MostBooked : public solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int res = 0, maxCnt = 0;
        vector<long long> cnt(n, 0), endTime(n, -1);
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        for (auto &meeting : meetings) {
            bool flag = true;
            long long minTime = endTime[0], minIdx = 0;
            for (int i = 0; i < n; ++i) {
                if (endTime[i] <= meeting[0]) {
                    flag = false;
                    endTime[i] = meeting[1];
                    ++cnt[i];
                    break;
                }
                if (endTime[i] < minTime) {
                    minTime = endTime[i];
                    minIdx = i;
                }
            }
            if (flag) {
                endTime[minIdx] += (meeting[1] - meeting[0]);
                ++cnt[minIdx];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                res = i;
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2402_MOSTBOOKED_H
