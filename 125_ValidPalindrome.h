//
// Created by Ke Wang on 10/29/24.
//

#ifndef INC_125_VALIDPALINDROME_H
#define INC_125_VALIDPALINDROME_H

#include "solution.h"

class ValidPalindrome : public solution {
public:
    bool isUppercase(char c) {
        return c >= 'A' && c <= 'Z';
    }

    char lowerCase(char c) {
        if (isUppercase(c)) {
            return 'a' + (c - 'A');
        }
        return c;
    }

    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                ++i;
            } else if (!isAlphanumeric(s[j])) {
                --j;
            } else {
                if (lowerCase(s[i]) != lowerCase(s[j])) {
                    return false;
                }
                ++i;
                --j;
            }
        }
        return true;
    }
};

#endif //INC_125_VALIDPALINDROME_H
