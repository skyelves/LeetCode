//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_56_MERGE_H
#define LEETCODE_56_MERGE_H

#include "solution.h"

class Merge : public solution {
public:
//    // O(N*range)
//    vector<vector<int>> merge(vector<vector<int>> &intervals) {
//        int myi[10005] = {0};
//        for (int i = 0; i < 10005; ++i) {
//            myi[i] = -1;
//        }
//        vector<vector<int>> res;
//        for (int i = 0; i < intervals.size(); ++i) {
//            int start = intervals[i][0], end = intervals[i][1];
//            int s = myi[start], e = myi[end];
//            if (s == -1) {
//                s = start;
//                myi[start] = start;
//            }
//            if (s != e) {
//                for (int j = end + 1; j < 10005; ++j) {
//                    if (myi[j] == e && myi[j] != -1) {
//                        myi[j] = s;
//                    }
//                }
//                for (int j = start; j <= end; ++j) {
//                    myi[j] = s;
//                }
//            }
//        }
//        int start = -1;
//        for (int i = 0; i < 10005; ++i) {
//            if (start == -1) {
//                if (myi[i] == i) {
//                    start = i;
//                }
//            } else {
//                if (myi[i] != start) {
//                    res.push_back({start, i - 1});
//                    start = myi[i];
//                }
//            }
//        }
//        return res;
//    }
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(intervals[i][1], end);
            }
        }
        res.push_back({start, end});
        return res;
    }

    void check() {
        vector<vector<int>> intervals = {{1,  3},
                                         {2,  6},
                                         {8,  10},
                                         {15, 18}};
        auto res = merge(intervals);
        for (auto i : res) {
            cout << i[0] << " " << i[1] << endl;
        }
    }
};

#endif //LEETCODE_56_MERGE_H
