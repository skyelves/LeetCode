//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_72_MINDISTANCE_H
#define LEETCODE_72_MINDISTANCE_H

#include "solution.h"

class MinDistance : public solution {
public:
    int minDistance(string word1, string word2) {
        int res = 0;
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));
        for (int i = 0; i <= len1; ++i) { dp[i][0] = i; }
        for (int i = 0; i <= len2; ++i) { dp[0][i] = i; }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }

    void check() {
        string word1 = "intention", word2 = "execution";
        int res = minDistance(word1, word2);
        cout << res << endl;
    }
};

#endif //LEETCODE_72_MINDISTANCE_H
