//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_1024_VIDEOSTITCHING_H
#define LEETCODE_1024_VIDEOSTITCHING_H

#include "solution.h"

class VideoStitching : public solution {
public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        int res = 0;
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        int curr = 0, idx = 0;
        while (curr < time) {
            int maxEnd = 0;
            while (idx < clips.size() && clips[idx][0] <= curr) {
                maxEnd = max(maxEnd, clips[idx][1]);
                ++idx;
            }
            if (maxEnd == 0)
                return -1;
            curr = maxEnd;
            ++res;
        }

        return res;
    }

    void check() {
        vector<vector<int>> clips{{0, 2},
                                  {4, 6},
                                  {8, 10},
                                  {1, 9},
                                  {1, 5},
                                  {5, 9}};
        int time = 10;
        cout << videoStitching(clips, time) << endl;
    }
};

#endif //LEETCODE_1024_VIDEOSTITCHING_H
