//
// Created by Ke Wang on 11/1/24.
//

#ifndef INC_10_REGULAREXPRESSIONMATCHING_H
#define INC_10_REGULAREXPRESSIONMATCHING_H

#include "solution.h"

class RegularExpressionMatching : public solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= m; ++j) {
            if (p[j - 1] == '*' && dp[0][j - 2]) {
                dp[0][j] = true;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '.') {
                    if (dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (p[j - 1] == '*') {
                    if (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = true;
                    } else if (dp[i][j - 2] || dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                } else {
                    if (s[i - 1] == p[j - 1] && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[n][m];
    }

    void check() override {
        string s = "aaa", p = ".*";
        cout << isMatch(s, p) << endl;
    }
};

#endif //INC_10_REGULAREXPRESSIONMATCHING_H
