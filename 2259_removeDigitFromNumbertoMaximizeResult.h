//
// Created by 王柯 on 7/25/22.
//

#ifndef LEETCODE_2259_REMOVEDIGITFROMNUMBERTOMAXIMIZERESULT_H
#define LEETCODE_2259_REMOVEDIGITFROMNUMBERTOMAXIMIZERESULT_H

#include "solution.h"

class RemoveDigit : public solution {
public:
    string removeDigit(string number, char digit) {
        string res;
        int cnt = count(number.begin(), number.end(), digit);
        int len = number.size();
        for (int i = 0; i < len; ++i) {
            if (number[i] != digit)
                continue;
            if (cnt == 1 || number[i + 1] > number[i]) {
                res = number.substr(0, i) + number.substr(i + 1, len);
                break;
            }
            cnt--;
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2259_REMOVEDIGITFROMNUMBERTOMAXIMIZERESULT_H
