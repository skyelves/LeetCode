//
// Created by 王柯 on 12/7/22.
//

#ifndef LEETCODE_629_KINVERSEPAIRS_H
#define LEETCODE_629_KINVERSEPAIRS_H

#include "solution.h"

class KInversePairs : public solution {
public:
    int kInversePairs(int n, int k) {
        int res = 0, mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j + 1 > i - 1) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - i + 1] - dp[i - 1][j + 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
                }
                dp[i][j] = dp[i][j] >= 0 ? dp[i][j] %= mod : dp[i][j] + mod;
            }
        }

        return dp[n][k];
    }

    void check() {
        int n = 1000, k = 1000;
        int res = kInversePairs(n, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_629_KINVERSEPAIRS_H
