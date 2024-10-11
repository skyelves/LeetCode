//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_8_STRINGTOINTEGER_H
#define LEETCODE_8_STRINGTOINTEGER_H

#include "solution.h"

class StringToInteger : public solution {
public:
    int myAtoi(string s) {
        int64_t res = 0, start = -1, end = -1, sign = 1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '-' || s[i] == '+' || isDigit(s[i])) {
                if (s[i] == '-' || s[i] == '+') {
                    ++i;
                }
                start = i;
                if (i > 0 && s[i - 1] == '-') {
                    sign = -1;
                }
                for (int j = i; j < s.size(); ++j) {
                    if (isDigit(s[j])) {
                        res *= 10;
                        res += (s[j] - '0') * sign;
                        if (res > INT32_MAX) {
                            return INT32_MAX;
                        } else if (res < INT32_MIN) {
                            return INT32_MIN;
                        }
                    } else {
                        break;
                    }
                }
            }
            break;
        }
        if (start == -1) {
            return 0;
        }
        return res;
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
};

#endif //LEETCODE_8_STRINGTOINTEGER_H
