//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_1326_MINTAPS_H
#define LEETCODE_1326_MINTAPS_H

#include "solution.h"

class MinTaps : public solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        int res = 0;
        vector<pair<int, int>> taps; // <start, end>
        for (int i = 0; i <= n; ++i) {
            taps.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(taps.begin(), taps.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
        int nextStart = 0, idx = 0;
        while (nextStart < n) {
            int maxRange = 0;
            while (idx <= n && taps[idx].first <= nextStart) {
                maxRange = max(maxRange, taps[idx].second);
                ++idx;
            }
            if (maxRange == 0)
                return -1;
            nextStart = maxRange;
            ++res;
        }
        return res;
    }

    void check() {
        int n = 5;
        vector<int> ranges{3,4,1,1,0,0};
        int res = minTaps(n, ranges);
        cout << res << endl;
    }
};

#endif //LEETCODE_1326_MINTAPS_H
