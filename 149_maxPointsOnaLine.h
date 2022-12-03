//
// Created by 王柯 on 12/2/22.
//

#ifndef LEETCODE_149_MAXPOINTSONALINE_H
#define LEETCODE_149_MAXPOINTSONALINE_H

#include "solution.h"

class MaxPoints : public solution {
public:
    inline double slope(vector<int> &n1, vector<int> &n2) {
        if (n1[0] == n2[0])
            return 1000000;
        return ((double) n1[1] - n2[1]) / (n1[0] - n2[0]);
    }

    int maxPoints(vector<vector<int>> &points) {
        int res = 0;
        int num = points.size();
        if (num < 3)
            return num;
        for (int i = 0; i < num; ++i) {
            unordered_map<double, int> mm;
            for (int j = i + 1; j < num; ++j) {
                double s = slope(points[i], points[j]);
                s *= 1000000;
                s /= 1000000;
                ++mm[s];
            }
            for (auto &i : mm) {
                res = max(res, i.second);
            }
        }
        return res + 1;
    }

    void check() {
        vector<vector<int>> points{{1, 1},
                                   {3, 2},
                                   {5, 3},
                                   {4, 1},
                                   {2, 3},
                                   {1, 4}};
        int res = maxPoints(points);
        cout << res << endl;
    }

};

#endif //LEETCODE_149_MAXPOINTSONALINE_H
