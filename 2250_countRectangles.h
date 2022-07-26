//
// Created by 王柯 on 7/26/22.
//

#ifndef LEETCODE_2250_COUNTRECTANGLES_H
#define LEETCODE_2250_COUNTRECTANGLES_H

#include "solution.h"

class CountRectangles : public solution {
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        sort(rectangles.begin(), rectangles.end());
        map<int, vector<int> > mm;
        for (auto i : rectangles) {
            mm[i[1]].push_back(i[0]);
        }
        vector<int> res;
        for (auto point : points) {
            int cnt = 0;
            int x = point[0], y = point[1];
            auto iter = mm.lower_bound(y);
            for (; iter != mm.end(); iter++) {
                auto tmp = iter->second;
                auto lower = lower_bound(tmp.begin(), tmp.end(), x);
                cnt += (tmp.end() - lower);
            }

            res.push_back(cnt);
        }
        return res;
    }

    void check() {
        vector<vector<int>> rectangles{
                {4, 7},
                {4, 9},
                {8, 5},
                {6, 2},
                {6, 4}
        }, points{
                {4, 2},
                {5, 6}
        };
        vector<int> res = countRectangles(rectangles, points);
        for (auto i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_2250_COUNTRECTANGLES_H
