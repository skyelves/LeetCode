//
// Created by Ke Wang on 10/19/24.
//

#ifndef INC_65_VALIDNUMBER_H
#define INC_65_VALIDNUMBER_H

#include "solution.h"

class ValidNumber : public solution {
public:
    bool isNumber(string s) {
        int j = 0;
        for (; j < s.size(); ++j) {
            if (s[j] == 'e' || s[j] == 'E') {
                break;
            }
        }
        // with exponent
        if (j < s.size()) {
            // 'e' is not the leading or ending char
            if (j == s.size() - 1 || j == 0) {
                return false;
            }
            bool res1 = isDecimal(s, 0, j - 1) || isInteger(s, 0, j - 1);
            bool res2 = isInteger(s, j + 1, s.size() - 1);
            return res1 && res2;
        }
        return isDecimal(s, 0, j - 1) || isInteger(s, 0, j - 1);
    }

    bool isDigits(string &s, int i, int j) {
        if (i > j) {
            return false;
        }
        for (; i <= j; ++ i) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                return false;
            }
        }
        return true;
    }

    bool isDecimal(string &s, int i, int j) {
        if (j - i < 1) {
            return false;
        }
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        int k = i;
        for (; k <= j; ++k) {
            if (s[k] == '.') {
                break;
            }
        }

        if (k == i) {
            return isDigits(s, i + 1, j);
        } else if (k == j) {
            return isDigits(s, i, j - 1);
        } else if (k > i && k < j) {
            return isDigits(s, i, k - 1) && isDigits(s, k + 1, j);
        }
        return false;
    }

    bool isInteger(string &s, int i, int j) {
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        return isDigits(s, i, j);
    }

    void check() {
        string s = "35k";
        cout << isNumber(s) << endl;
    }
};

#endif //INC_65_VALIDNUMBER_H
