//
// Created by Admin on 10/15/2024.
//

#ifndef LEETCODE_1762_BUILDINGSWITHANOCEANVIEW_H
#define LEETCODE_1762_BUILDINGSWITHANOCEANVIEW_H

#include "solution.h"

class BuildsWithAnOceanView : public solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        res.push_back(heights.size() - 1);
        int tmpMax = heights[heights.size() - 1];
        for (int i = heights.size() - 2; i >= 0; --i) {
            if (heights[i] > tmpMax) {
                res.push_back(i);
                tmpMax = max(tmpMax, heights[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODE_1762_BUILDINGSWITHANOCEANVIEW_H
