//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_8_STRINGTOINTEGER_H
#define LEETCODE_8_STRINGTOINTEGER_H

#include "solution.h"

class StringToInteger : public solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        trim(idx, s);
        int sign = getSign(idx, s);
        skipLeadingZeros(idx, s);
        long long res = getNumber(idx, s) * sign;
        if (res < INT32_MIN) {
            return INT32_MIN;
        } else if (res > INT32_MAX) {
            return INT32_MAX;
        }
        return res;
    }

    // trim leading whitespace
    void trim(int &idx, string &s) {
        while(s[idx] == ' ') {
            ++idx;
        }
    }

    int getSign(int &idx, string &s) {
        if (s[idx] == '-') {
            ++idx;
            return -1;
        } else if (s[idx] == '+') {
            ++idx;
            return 1;
        }
        return 1;
    }

    void skipLeadingZeros(int &idx, string &s) {
        while(s[idx] == '0') {
            ++idx;
        }
    }

    long long getNumber(int &idx, string &s) {
        long long res = 0;
        int n = s.size();
        while(idx < n && s[idx] >= '0' && s[idx] <= '9' && res <= INT32_MAX) {
            res *= 10;
            res += s[idx] - '0';
            ++idx;
        }
        return res;
    }
};

#endif //LEETCODE_8_STRINGTOINTEGER_H
