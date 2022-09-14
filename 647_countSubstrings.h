//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_647_COUNTSUBSTRINGS_H
#define LEETCODE_647_COUNTSUBSTRINGS_H

#include "solution.h"

class CountSubstrings : public solution {
public:
//    bool is_palindrome(int l, int r, string &s) {
//        if (l == r)
//            return true;
//        int cnt = (r - l + 1) / 2;
//        for (int i = 0; i < cnt; ++i) {
//            if (s[l + i] != s[r - i])
//                return false;
//        }
//        return true;
//    }
//
//    int countSubstrings(string s) {
//        int res = 0;
//        int len = s.size();
//        for (int i = 0; i < len; ++i) {
//            for (int j = i; j < len; ++j) {
//                if (is_palindrome(i, j, s))
//                    res++;
//            }
//        }
//        return res;
//    }

    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();
        vector<vector<bool> > dp(len + 1, vector<bool>(len, false));
        // dp[i][j] is true: substring with len i starting from j is palindrome
        for (int i = 0; i < len; ++i) {
            dp[1][i] = true;
        }
        res += len;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                res++;
                dp[2][i] = true;
            }
        }
        for (int i = 3; i <= len; ++i) {
            for (int j = 0; j < len - i + 1; ++j) {
                if (dp[i - 2][j + 1] && s[j] == s[j + i - 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }


    void check() {
        string s = "aaa";
        int res = countSubstrings(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_647_COUNTSUBSTRINGS_H
