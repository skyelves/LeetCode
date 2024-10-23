//
// Created by Ke Wang on 10/22/24.
//

#ifndef INC_986_INTERVALLISTINTERSECTIONS_H
#define INC_986_INTERVALLISTINTERSECTIONS_H

#include "solution.h"

class IntervalListIntersections : public solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i1 = 0, i2 = 0;
        while (i1 < firstList.size() && i2 < secondList.size()) {
            int l1 = firstList[i1][0];
            int r1 = firstList[i1][1];
            int l2 = secondList[i2][0];
            int r2 = secondList[i2][1];
            if ((l1 - r2 <= 0 && r1 - l2 >= 0) || (l1 - r2 >= 0 && r1 - l2 <= 0)) {
                // with intersection
                res.push_back({max(l1, l2), min(r1, r2)});
            }
            if (r1 < r2) {
                ++i1;
            } else {
                ++i2;
            }
        }
        return res;
    }
};

#endif //INC_986_INTERVALLISTINTERSECTIONS_H
