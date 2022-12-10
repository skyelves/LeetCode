//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_1510_WINNERSQUAREGAME_H
#define LEETCODE_1510_WINNERSQUAREGAME_H

#include "solution.h"

class WinnerSquareGame : public solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        for (int i = 2; i <= n; ++i) {
            int sq = sqrt(i);
            for (int j = sq; j > 0; --j) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

#endif //LEETCODE_1510_WINNERSQUAREGAME_H
