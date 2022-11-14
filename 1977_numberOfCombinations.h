//
// Created by 王柯 on 11/13/22.
//

#ifndef LEETCODE_1977_NUMBEROFCOMBINATIONS_H
#define LEETCODE_1977_NUMBEROFCOMBINATIONS_H

#include "solution.h"

class NumberOfCombinations : public solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0')
            return 0;
        int res = 0, len = num.size();
        vector<vector<int>> lcp(len + 1, vector<int>(len + 1, 0)); // longest common prefix start at i and j
        for (int i = len - 1; i >= 0; --i) {
            for (int j = len - 1; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }
        vector<vector<int>> dp(len, vector<int>(len, 0)); // dp[i][j] denotes the valid #seq in num[i, j]
        vector<vector<int>> preSum(len, vector<int>(len,
                                                    0)); // preSum[i][j] denotes the sum: dp[0][j] + dp[1][j] + ... + dp[i][j]
        for (int i = 0; i < len; ++i) {
            dp[0][i] = 1;
            preSum[0][i] = 1;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (num[i] != '0') {
                    int startIdx = max(0, i - (j - i));
                    dp[i][j] = startIdx > 0 ? (preSum[i - 1][i - 1] - preSum[startIdx - 1][i - 1] + 1000000007) %
                                              1000000007 : preSum[i - 1][i - 1];
                    if (startIdx > 0) {
                        int tmpLcp = lcp[startIdx - 1][i];
                        if (tmpLcp >= j - i + 1 || num[startIdx - 1 + tmpLcp] < num[i + tmpLcp]) {
                            dp[i][j] += dp[startIdx - 1][i - 1];
                            dp[i][j] %= 1000000007;
                        }
                    }
                }
                preSum[i][j] = (preSum[i - 1][j] + dp[i][j]) % 1000000007;
            }
        }

        return preSum[len - 1][len - 1];
    }

    void check() {
        string num = "1212";
        int res = numberOfCombinations(num);
        cout << res << endl;
    }
};

#endif //LEETCODE_1977_NUMBEROFCOMBINATIONS_H
