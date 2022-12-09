//
// Created by 王柯 on 12/8/22.
//

#ifndef LEETCODE_1473_PAINTHOUSEIII_H
#define LEETCODE_1473_PAINTHOUSEIII_H

#include "solution.h"

class PaintHouseIII : public solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX / 2)));
        int res = INT_MAX;
        if (houses[0] == 0) {
            for (int i = 0; i < n; ++i) {
                dp[0][i + 1][1] = cost[0][i];
            }
        } else {
            dp[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= min(i + 1, target); ++k) {
                    if (houses[i] != 0) {
                        if (houses[i] == j)
                            for (int l = 1; l <= n; ++l) {
                                if (houses[i] != l)
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k - 1]);
                                else
                                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k]);
                            }
                    } else {
                        for (int l = 1; l <= n; ++l) {
                            if (l == j) {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k] + cost[i][j - 1]);
                            } else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k - 1] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            res = min(res, dp[m - 1][i][target]);
        }
        return res >= INT_MAX / 2 ? -1 : res;
    }

    void check() {
        vector<int> houses{0, 2, 1, 2, 0};
        vector<vector<int>> cost{{1,  10},
                                 {10, 1},
                                 {10, 1},
                                 {1,  10},
                                 {5,  1}};
        int m = 5, n = 2, target = 3;
        int res = minCost(houses, cost, m, n, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_1473_PAINTHOUSEIII_H
