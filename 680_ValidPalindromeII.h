//
// Created by Admin on 9/26/2024.
//

#ifndef LEETCODE_680_VALIDPALINDROMEII_H
#define LEETCODE_680_VALIDPALINDROMEII_H

#include "solution.h"

class ValidPalindromeII : public solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                bool res1 = false, res2 = false;
                if (s[i+1] == s[j]) {
                    res1 = isPalindrome(s, i + 1, j);
                }
                if (s[i] == s[j - 1]) {
                    res2 = isPalindrome(s, i, j - 1);
                }
                return res1 | res2;
            }
        }
        return true;
    }

    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    void check() {
        string s = "deeee";
        cout << validPalindrome(s) << endl;

    }
};

#endif //LEETCODE_680_VALIDPALINDROMEII_H
