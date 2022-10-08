//
// Created by 王柯 on 10/8/22.
//

#ifndef LEETCODE_2361_MINIMUMCOSTS_H
#define LEETCODE_2361_MINIMUMCOSTS_H

#include "solution.h"

class MinimumCosts : public solution {
public:
    vector<long long> minimumCosts(vector<int> &regular, vector<int> &express, int expressCost) {
        int n = regular.size();
        vector<long long> res(n, 0);
        vector<long long> dp1(n + 1, 0), dp2(n + 1, 0);
        dp2[0] = expressCost;
        for (int i = 0; i < n; ++i) {
            dp1[i + 1] = min(dp1[i] + regular[i], dp2[i] + express[i]);
            dp2[i + 1] = min(dp1[i + 1] + expressCost, dp2[i] + express[i]);
            res[i] = (min(dp1[i + 1], dp2[i + 1]));
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2361_MINIMUMCOSTS_H
