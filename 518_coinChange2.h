//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_518_COINCHANGE2_H
#define LEETCODE_518_COINCHANGE2_H

#include "solution.h"

class CoinChange2 : public solution {
public:
    int change(int amount, vector<int> &coins) {
        int len = coins.size();
        vector<int> dp(amount + 1, 0);
        for (int i = 0; i <= amount; i += coins[0]) {
            dp[i] = 1;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i]) {
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }

    void check() {
        vector<int> coins{1, 2, 5};
        int amount = 5;
        int res = change(amount, coins);
        cout << res << endl;
    }
};

#endif //LEETCODE_518_COINCHANGE2_H
