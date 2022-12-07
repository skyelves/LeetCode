//
// Created by 王柯 on 12/7/22.
//

#ifndef LEETCODE_13_ROMANTOINT_H
#define LEETCODE_13_ROMANTOINT_H

#include "solution.h"

class RomanToInt : public solution {
public:
    map<char, int> mm{{'I', 1},
                      {'V', 5},
                      {'X', 10},
                      {'L', 50},
                      {'C', 100},
                      {'D', 500},
                      {'M', 1000}};
    char last = '\0';

    int romanToInt(string s) {
        int res = 0;
        for (auto &c : s) {
            res += mm[c];
            if ((last == 'I' && (c == 'V' || c == 'X')) || (last == 'X' && (c == 'L' || c == 'C')) || (last == 'C' && (c == 'D' || c == 'M'))) {
                res -= 2 * mm[last];
            }
            last = c;
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_13_ROMANTOINT_H
