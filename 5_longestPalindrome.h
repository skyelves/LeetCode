//
// Created by 王柯 on 9/14/22.
//

#ifndef LEETCODE_5_LONGESTPALINDROME_H
#define LEETCODE_5_LONGESTPALINDROME_H

#include "solution.h"

class LongestPalindrome : public solution {
public:
    pair<int, int> expand(string &s, int l, int r) {
        int len = s.size();
        while (l >= 0 && r < len && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l + 1, r - 1};
    }

    string longestPalindrome(string s) {
        int res_l = 0, res_len = 0;
        int len = s.size();
        for (int i = 0; i < len - 1; ++i) {
            auto tmp1 = expand(s, i, i);
            auto tmp2 = expand(s, i, i + 1);
            int len1 = tmp1.second - tmp1.first;
            int len2 = tmp2.second - tmp2.first;
            if (len1 >= len2 && len1 > res_len) {
                res_l = tmp1.first;
                res_len = len1;
            } else if (len2 > len1 && len2 > res_len) {
                res_l = tmp2.first;
                res_len = len2;
            }
        }
        return s.substr(res_l, res_len + 1);
    }

    void check() {
        string s = "babad";
        string res = longestPalindrome(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_5_LONGESTPALINDROME_H
