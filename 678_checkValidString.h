//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_678_CHECKVALIDSTRING_H
#define LEETCODE_678_CHECKVALIDSTRING_H

#include "solution.h"

class CheckValidString : public solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        if (s[0] == ')') {
            return false;
        } else if (s[0] == '(') {
            dp[0][1] = true;
        } else {
            dp[0][0] = true;
            dp[0][1] = true;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == '(') {
                    if (dp[i - 1][j]) {
                        dp[i][j + 1] = true;
                    }
                } else if (s[i] == ')') {
                    if (dp[i - 1][j] && j > 0) {
                        dp[i][j - 1] = true;
                    }
                } else {
                    if (dp[i - 1][j]) {
                        dp[i][j] = true;
                        dp[i][j + 1] = true;
                        if (j > 0) {
                            dp[i][j - 1] = true;
                        }
                    }
                }
            }
        }
        return dp[len - 1][0];
    }

    void check() {
        string s = "***)(**";
        bool res = checkValidString(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_678_CHECKVALIDSTRING_H
