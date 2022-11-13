//
// Created by 王柯 on 11/13/22.
//

#ifndef LEETCODE_1787_MINXORCHANGES_H
#define LEETCODE_1787_MINXORCHANGES_H

#include "solution.h"

class MinXORChanges : public solution {
public:
    int minChanges(vector<int> &nums, int k) {
        int res = 0, len = nums.size();
        vector<map<int, int>> vv(k, map<int, int>());
        vector<int> cnt(k, 0);
        for (int i = 0; i < len; ++i) {
            ++vv[i % k][nums[i]];
            ++cnt[i % k];
        }
        int minPrev = INT_MAX;
        vector<vector<int>> dp(k, vector<int>(1024,
                                              INT_MAX)); // dp[i][j] denotes the minChanges for until i_th nums, the xor res is j
        for (int i = 0; i < 1024; ++i) {
            dp[0][i] = cnt[0] - vv[0][i];
            minPrev = min(minPrev, dp[0][i]);
        }
        for (int i = 1; i < k; ++i) {
            auto &mm = vv[i];
            int tmpMin = INT_MAX;
            for (int j = 0; j < 1024; ++j) {
                for (auto &l : mm) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ l.first] + cnt[i] - l.second);
                }
                dp[i][j] = min(dp[i][j], minPrev + cnt[i]);
                tmpMin = min(tmpMin, dp[i][j]);
            }
            minPrev = tmpMin;
        }

        return dp[k - 1][0];
    }

    void check() {
        int k = 3;
        vector<int> nums{1, 2, 4, 1, 2, 5, 1, 2, 6};
        int res = minChanges(nums, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_1787_MINXORCHANGES_H
