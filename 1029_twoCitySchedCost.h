//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1029_TWOCITYSCHEDCOST_H
#define LEETCODE_1029_TWOCITYSCHEDCOST_H

#include "solution.h"

class TwoCitySchedCost : public solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int len = costs.size();
        vector<int> dp(len + 1); // dp[i][j] denotes from 0 to i-1 people, there are j people flying to city a
        dp[0] = costs[0][1];
        dp[1] = costs[0][0];
        for (int i = 2; i <= len; ++i) {
            dp[i] = dp[i - 1] + costs[i - 1][0];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j] + costs[i - 1][1], dp[j - 1] + costs[i - 1][0]);
            }
            dp[0] = dp[0] + costs[i - 1][1];
        }
        return dp[len / 2];
    }

    void check() {
        vector<vector<int>> costs = {{10,  20},
                                     {30,  200},
                                     {400, 50},
                                     {30,  20}};
//        vector<vector<int>> costs = {{259, 770},
//                                     {448, 54},
//                                     {926, 667},
//                                     {184, 139},
//                                     {840, 118},
//                                     {577, 469}};
        int res = twoCitySchedCost(costs);
        cout << res << endl;
    }
};

#endif //LEETCODE_1029_TWOCITYSCHEDCOST_H
