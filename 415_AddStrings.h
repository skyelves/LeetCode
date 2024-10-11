//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_415_ADDSTRINGS_H
#define LEETCODE_415_ADDSTRINGS_H

#include "solution.h"

class AddStrings : public solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int co = 0, i = 0, j = 0;
        while(i < num1.size() || j < num2.size()) {
            int n1 = i < num1.size() ? num1[i] - '0' : 0, n2 = j < num2.size() ? num2[j] - '0' : 0;
            n1 += n2 + co;
            if (n1 >= 10) {
                co = 1;
                n1 -= 10;
            } else {
                co = 0;
            }
            res.push_back('0' + n1);
            ++i;
            ++j;
        }
        if (co == 1) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODE_415_ADDSTRINGS_H
