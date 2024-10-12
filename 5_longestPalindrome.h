//
// Created by 王柯 on 9/14/22.
//

#ifndef LEETCODE_5_LONGESTPALINDROME_H
#define LEETCODE_5_LONGESTPALINDROME_H

#include "solution.h"

class LongestPalindrome : public solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), l = 0, r = 0;
        string res = s.substr(0, 1);
        vector<int> d1(n, 1), d2(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = i >= r ? 1 : min(d1[l + r - i], r - i - 1);
            while (i + j < n && i - j >= 0 && s[i + j] == s[i - j]) {
                ++j;
            }
            d1[i] = j;
            if (i + j - 1 > r) {
                r = i + j - 1;
                l = i - j + 1;
            }
            if (2 * j - 1 > res.size()) {
                res = s.substr(i - j + 1, 2 * j - 1);
            }
        }

        l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            int j = i >= r ? 0 : min(d2[l + r - i + 1], r - i - 1);
            while (i + j < n && i - 1 - j >= 0 && s[i + j] == s[i - 1 - j]) {
                ++j;
            }
            d2[i] = j;
            if (i + j - 1 > r) {
                r = i + j - 1;
                l = i - j ;
            }
            if (2 * j > res.size()) {
                res = s.substr(i - j, 2 * j);
            }
        }

        return res;
    }

    void check() {
        string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        string res = longestPalindrome(s);
        cout << res.size() << ": " << res << endl;
    }
};

#endif //LEETCODE_5_LONGESTPALINDROME_H
