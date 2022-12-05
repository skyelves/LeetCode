//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_730_COUNTPALINDROMICSUBSEQUENCES_H
#define LEETCODE_730_COUNTPALINDROMICSUBSEQUENCES_H

#include "solution.h"

class CountPalindromicSubsequences : public solution {
public:
    int countPalindromicSubsequences(string s) {
        int res = 0, len = s.size(), mod = 1000000007;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        for (int k = 1; k < len; ++k) {
            for (int i = 0; i < len - k; ++i) {
                int j = i + k;
                if (s[i] == s[j]) {
                    int low = i + 1, high = j - 1;
                    while(s[i] != s[low]) ++low;
                    while(s[j] != s[high]) --high;
                    if (low > high) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (low == high) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1];
                    }
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mod : dp[i][j] % mod;
            }
        }

        return dp[0][len - 1];
    }

    void check() {
        string s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
        int res = countPalindromicSubsequences(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_730_COUNTPALINDROMICSUBSEQUENCES_H
