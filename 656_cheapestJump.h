//
// Created by 王柯 on 11/1/22.
//

#ifndef LEETCODE_656_CHEAPESTJUMP_H
#define LEETCODE_656_CHEAPESTJUMP_H

#include "solution.h"

class CheapestJump : public solution {
public:
    vector<int> cheapestJump(vector<int> &coins, int maxJump) {
        vector<int> res;
        int len = coins.size();
        vector<int> dp(len + 1, 10000000), path(len + 1, -1);
        dp[len - 1] = coins[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            if (coins[i] == -1) continue;
            for (int j = 1; j <= min(len - 1 - i, maxJump); ++j) {
                if (coins[i + j] == -1 || dp[i + j] == 10000000) continue;
                dp[i] = min(dp[i], dp[i + j] + coins[i]);
            }
        }
        if (dp[0] == 10000000) return res;
        int tmp = 0;
        res.push_back(1);
        while (tmp != len - 1) {
            int minCost = INT_MAX;
            int minIdx = -1;
            for (int i = 1; i <= min(maxJump, len - 1 - tmp); ++i) {
                if (dp[tmp + i] < minCost) {
                    minCost = dp[tmp + i];
                    minIdx = tmp + i;
                }
            }
            tmp = minIdx;
            res.push_back(tmp + 1);
        }
        return res;
    }

    void check() {
        vector<int> coins{1, 2, 4, -1, 2};
        int maxJump = 2;
        vector<int> res = cheapestJump(coins, maxJump);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_656_CHEAPESTJUMP_H
