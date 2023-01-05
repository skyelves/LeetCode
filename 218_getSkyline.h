//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_218_GETSKYLINE_H
#define LEETCODE_218_GETSKYLINE_H

#include "solution.h"

class GetSkyline : public solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> res;
        vector<int> x, y;
        unordered_map<int, int> edgeIndex;
        int len = buildings.size();
        for (int i = 0; i < len; ++i) {
            x.push_back(buildings[i][0]);
            x.push_back(buildings[i][1]);
        }
        sort(x.begin(), x.end());
        int xLen = unique(x.begin(), x.end()) - x.begin();
        x.resize(xLen);
        y.resize(xLen);
        for (int i = 0; i < xLen; ++i) {
            edgeIndex[x[i]] = i;
        }
        for (int i = 0; i < len; ++i) {
            int leftIndex = edgeIndex[buildings[i][0]], rightIndex = edgeIndex[buildings[i][1]], height = buildings[i][2];
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                y[idx] = max(y[idx], height);
            }
        }
        int currY = 0;
        for (int i = 0; i < xLen; ++i) {
            if (y[i] != currY) {
                res.push_back({x[i], y[i]});
                currY = y[i];
            }
        }
        return res;
    }

    void check() {
        vector<vector<int>> buildings{{2,  9,  10},
                                      {3,  7,  15},
                                      {5,  12, 12},
                                      {15, 20, 10},
                                      {19, 24, 8}};
        auto res = getSkyline(buildings);
        for (auto &i : res) {
            cout << i[0] << " " << i[1] << endl;
        }
    }
};

#endif //LEETCODE_218_GETSKYLINE_H
