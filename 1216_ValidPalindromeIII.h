//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_1216_VALIDPALINDROMEIII_H
#define LEETCODE_1216_VALIDPALINDROMEIII_H

#include "solution.h"

class ValidPalindromeIII : public solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size() + 1, 0));
        for (int len = 2; len <= s.size(); ++len) {
            for (int i = 0; i + len - 1 < s.size(); ++i) {
                int tmp = 1e5;
                if (s[i] == s[i + len - 1]) {
                    tmp = dp[i + 1][len - 2];
                }
                tmp = min(tmp, dp[i][len - 1] + 1);
                tmp = min(tmp, dp[i + 1][len - 1] + 1);
                dp[i][len] = tmp;
            }
        }
        return dp[0][s.size()] <= k;
    }

    void check() {
        string s = "abbababa";
        int k = 1;
        cout << isValidPalindrome(s, k) << endl;
    }
};

#endif //LEETCODE_1216_VALIDPALINDROMEIII_H
