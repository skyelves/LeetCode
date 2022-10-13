//
// Created by 王柯 on 10/12/22.
//

#ifndef LEETCODE_1048_LONGESTSTRCHAIN_H
#define LEETCODE_1048_LONGESTSTRCHAIN_H

#include "solution.h"

class LongestStrChain : public solution {
public:
    bool isPred(string &a, string &b) {
        if (b.size() == a.size() + 1) {
            int i = 0, j = 0;
            while (i < a.size() && j < b.size()) {
                if (a[i] == b[j]) {
                    ++i;
                    ++j;
                } else if (i == j) {
                    ++j;
                } else {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        int len = words.size(), res = 1;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPred(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    void check() {
        vector<string> words{"ksqvsyq", "ks", "kss", "czvh", "zczpzvdhx", "zczpzvh", "zczpzvhx", "zcpzvh", "zczvh",
                             "gr", "grukmj", "ksqvsq", "gruj", "kssq", "ksqsq", "grukkmj", "grukj", "zczpzfvdhx",
                             "gru"};
        int res = longestStrChain(words);
        cout << res << endl;
    }
};

#endif //LEETCODE_1048_LONGESTSTRCHAIN_H
