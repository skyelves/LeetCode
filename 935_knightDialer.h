//
// Created by 王柯 on 10/22/22.
//

#ifndef LEETCODE_935_KNIGHTDIALER_H
#define LEETCODE_935_KNIGHTDIALER_H

#include "solution.h"

class KnightDialer : public solution {
public:
    int knightDialer(int n) {
        map<int, vector<int>> mm{{0, {4, 6}},
                                 {1, {6, 8}},
                                 {2, {7, 9}},
                                 {3, {4, 8}},
                                 {4, {0, 3, 9}},
                                 {5, {}},
                                 {6, {0, 1, 7}},
                                 {7, {2, 6}},
                                 {8, {1, 3}},
                                 {9, {2, 4}}};
        long long res = 0;
        long long mod = 1000000007;
        vector<vector<long long>> dp(n, vector<long long>(10));
        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                long long tmp = 0;
                for (auto k : mm[j]) {
                    tmp += dp[i - 1][k];
                }
                dp[i][j] = tmp % mod;
            }
        }
        for (int i = 0; i < 10; ++i) {
            res += dp[n - 1][i];
            res %= mod;
        }

        return res % mod;
    }

    void check() {
        int n = 3131;
        int res = knightDialer(n);
        cout << res << endl;
    }
};

#endif //LEETCODE_935_KNIGHTDIALER_H
