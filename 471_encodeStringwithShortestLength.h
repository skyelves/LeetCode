//
// Created by 王柯 on 11/28/22.
//

#ifndef LEETCODE_471_ENCODESTRINGWITHSHORTESTLENGTH_H
#define LEETCODE_471_ENCODESTRINGWITHSHORTESTLENGTH_H

#include "solution.h"

class EncodeStringwithShortestLength : public solution {
public:
    string encodeStringwithShortestLength(string s) {
        int len = s.size();
        vector<vector<string>> dp(len, vector<string>(len, ""));
        for (int l = 1; l < 5; ++l) {
            for (int i = 0; i < len - l + 1; ++i) {
                dp[i][i + l - 1] = s.substr(i, l);
            }
        }
        for (int l = 5; l <= len; ++l) {
            for (int i = 0; i < len - l + 1; ++i) {
                int j = i + l - 1;
                string tmp = s.substr(i, l);
                dp[i][j] = tmp;
                for (int k = 1; k < l; ++k) {
                    string tmpStr = dp[i][i + k - 1] + dp[i + k][j];
                    if (tmpStr.length() < dp[i][j].length()) {
                        dp[i][j] = tmpStr;
                    }
                }
                for (int k = 1; k < l; ++k) {
                    if (l % k == 0) {
                        bool flag = true;
                        int cnt = l / k;
                        for (int p = 0; p < k; ++p) {
                            for (int m = 1; m < cnt; ++m) {
                                if (s[i + m * k + p] != s[i + p]) {
                                    flag = false;
                                    break;
                                }
                            }
                            if (!flag)
                                break;
                        }
                        if (flag) {
                            stringstream ss;
                            ss << cnt;
                            string tmpStr = ss.str() + "[" + dp[i][i + k - 1] + "]";
                            if (tmpStr.length() < dp[i][j].length()) {
                                dp[i][j] = tmpStr;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][len - 1];
    }

    void check() {
        string s = "abbbabbbcabbbabbbc";
        string res = encodeStringwithShortestLength(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_471_ENCODESTRINGWITHSHORTESTLENGTH_H
