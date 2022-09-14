//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_1328_BREAKPALINDROME_H
#define LEETCODE_1328_BREAKPALINDROME_H

#include "solution.h"

class BreakPalindrome : public solution {
public:
    string breakPalindrome(string palindrome) {
        int flag = true;
        int len = palindrome.size();
        if (len <= 1)
            return "";
        int mid = len % 2 ? len / 2 : -1;
        for (int i = 0; i < len; ++i) {
            if (i != mid && palindrome[i] != 'a') {
                palindrome[i] = 'a';
                flag = false;
                break;
            }
        }
        if (flag) {
            palindrome[len - 1] = 'b';
        }
        return palindrome;
    }

    void check() {
        string palindrome = "a";
        string res = breakPalindrome(palindrome);
        cout << res << endl;
    }
};

#endif //LEETCODE_1328_BREAKPALINDROME_H
