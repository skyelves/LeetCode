//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_1326_MINTAPS_H
#define LEETCODE_1326_MINTAPS_H

#include "solution.h"

class MinTaps : public solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        vector<pair<int, int>> taps;
        for (int i = 0; i <= n; ++i) {
            taps.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(taps.begin(), taps.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first != b.first)
                return a.first < b.first;
            else
                return a.second > b.second;
        });
        vector<int> dp(n, INT_MAX);
        int rightLimit = 0, idx = 0, res = 0;
        while (idx < n && rightLimit < n) {
            int nextLimit = -1;
            while (idx < n && taps[idx].first <= rightLimit) {
                nextLimit = max(nextLimit, taps[idx].second);
                ++idx;
            }
            if (nextLimit > rightLimit) {
                rightLimit = nextLimit;
                ++res;
            } else {
                return -1;
            }
        }
        return res;
    }

    void check() {
        int n = 8;
        vector<int> ranges{4,0,0,0,4,0,0,0,4};
        int res = minTaps(n, ranges);
        cout << res << endl;
    }
};

#endif //LEETCODE_1326_MINTAPS_H
