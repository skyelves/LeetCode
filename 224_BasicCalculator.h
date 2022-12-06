//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_224_BASICCALCULATOR_H
#define LEETCODE_224_BASICCALCULATOR_H

#include "solution.h"

class BasicCaculator : public solution {
public:
    int calculate(string s) {
        int res = 0, len = s.size();
        stack <pair<int, int>> ss;
        int tmp = 0, sign = 1;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] == '(') {
                ss.push({res, sign});
                res = 0;
                tmp = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += sign * tmp;
                res *= ss.top().second;
                res += ss.top().first;
                ss.pop();
                tmp = 0;
                sign = 1;
            } else if (s[i] == '+') {
                res += sign * tmp;
                sign = 1;
                tmp = 0;
            } else if (s[i] == '-') {
                res += sign * tmp;
                sign = -1;
                tmp = 0;
            } else {
                tmp *= 10;
                tmp += s[i] - '0';
            }
        }
        res += tmp * sign;

        return res;
    }

    void check() {
        string s = "-1 + 2";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_224_BASICCALCULATOR_H
