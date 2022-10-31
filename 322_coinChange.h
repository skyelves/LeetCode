//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_322_COINCHANGE_H
#define LEETCODE_322_COINCHANGE_H

#include "solution.h"

class CoinChange : public solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        int len = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(vector<int>(amount + 1, 1000000));
        for (int i = 0; i <= amount; i += coins[0]) {
            dp[i] = i / coins[0];
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] <= j) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == 1000000 ? -1 : dp[amount];

//        if (amount == 0)
//            return 0;
//        int len = coins.size();
//        int **dp = new int *[len];
//        for (int i = 0; i < len; ++i) {
//            dp[i] = new int[amount + 1];
//            for (int j = 0; j < amount + 1; ++j) {
//                dp[i][j] = INT_MAX - 1;
//            }
//        }
//        for (int i = 0; i <= amount; i += coins[0]) {
//            dp[0][i] = i / coins[0];
//        }
//        for (int i = 1; i < len; ++i) {
//            for (int j = 0; j <= amount; ++j) {
//                if (coins[i] > j) {
//                    dp[i][j] = dp[i - 1][j];
//                } else {
//                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
//                }
//            }
//        }
//        return dp[len - 1][amount] == INT_MAX - 1 ? -1 : dp[len - 1][amount];
    }

    void check() {
        vector<int> coins{2};
        int amount = 3;
        int res = coinChange(coins, amount);
        cout << res << endl;
    }
};

#endif //LEETCODE_322_COINCHANGE_H
