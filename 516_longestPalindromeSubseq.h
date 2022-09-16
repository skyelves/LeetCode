//
// Created by 王柯 on 9/14/22.
//

#ifndef LEETCODE_516_LONGESTPALINDROMESUBSEQ_H
#define LEETCODE_516_LONGESTPALINDROMESUBSEQ_H

#include "solution.h"

class LongestPalindromeSubseq : public solution {
public:
    int longestPalindromeSubseq(string s) {
        int res = 1;
        int len = s.size();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
            if (i != 0) {
                if (s[i] == s[i - 1]) {
                    dp[i][i - 1] = 2;
                    res = 2;
                } else
                    dp[i][i - 1] = 1;
            }
        }
        for (int i = 2; i < len; ++i) {
            for (int j = i - 2; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
                }
            }
        }
        return res;
    }

    void check() {
        string s = "cbbd";
        int res = longestPalindromeSubseq(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_516_LONGESTPALINDROMESUBSEQ_H
