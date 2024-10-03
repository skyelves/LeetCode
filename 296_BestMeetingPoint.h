//
// Created by Admin on 10/2/2024.
//

#ifndef LEETCODE_296_BESTMEETINGPOINT_H
#define LEETCODE_296_BESTMEETINGPOINT_H

#include "solution.h"

class BestMeetingPoint : public solution {
    int minTotalDistance(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), friendCnt = 0;
        vector<int> x(n, 0), y(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    ++x[i];
                    ++y[j];
                    ++friendCnt;
                }
            }
        }
        return findMinDistance(x, friendCnt) + findMinDistance(y, friendCnt);
    }

    int findMinDistance(vector<int> &x, int cnt) {
        int res = 0, tmpCnt = 0, medianCnt = cnt / 2;
        for (int i = 0; i < x.size(); ++i) {
            tmpCnt += x[i];
            if (tmpCnt > medianCnt) {
                for (int j = 0; j < x.size(); ++j) {
                    res += x[j] * abs(j - i);
                }
                break;
            }
        }
        return res;
    }
};

#endif //LEETCODE_296_BESTMEETINGPOINT_H
