//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_227_BASICCALCULATORII_H
#define LEETCODE_227_BASICCALCULATORII_H

#include "solution.h"

class BasicCalculatorII : public solution {
public:
    string removeSpace(string &s) {
        string res = "";
        for (char c : s) {
            if (c != ' ') {
                res.push_back(c);
            }
        }
        return res;
    }

    int getNumber(int &idx, string &s) {
        int res = 0;
        for (; idx < s.size(); ++idx) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                res *= 10;
                res += s[idx] - '0';
            } else {
                break;
            }
        }
        return res;
    }

    int calculate(string s) {
        s = removeSpace(s);
        int res = 0, idx = 0, n = s.size();
        int last = getNumber(idx, s);
        while (idx < n) {
            if (s[idx] == '+') {
                ++idx;
                res += last;
                last = getNumber(idx, s);
            } else if (s[idx] == '-') {
                ++idx;
                res += last;
                last = -1 * getNumber(idx, s);
            } else if (s[idx] == '*') {
                ++idx;
                last *= getNumber(idx, s);
            } else if (s[idx] == '/') {
                ++idx;
                last /= getNumber(idx, s);
            }
        }
        res += last;
        return res;
    }

    void check() {
        string s = "14/3*2";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_227_BASICCALCULATORII_H
