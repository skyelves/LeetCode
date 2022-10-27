//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_91_NUMDECODINGS_H
#define LEETCODE_91_NUMDECODINGS_H

#include "solution.h"

class NumDecodings : public solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (s[0] == '0')
            return 0;
        vector<int> dp(len, 0);
        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
            int num1 = s[i] - '0', num2 = 10 * (s[i - 1] - '0') + num1;
            if (num1 > 0) {
                dp[i] += dp[i - 1];
            }
            if (num2 >= 10 && num2 <= 26) {
                if (i >= 2)
                    dp[i] += dp[i - 2];
                else
                    dp[i] += 1;
            }
        }
        return dp[len - 1];
    }

    void check() {
        string s = "06";
        int res = numDecodings(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_91_NUMDECODINGS_H
