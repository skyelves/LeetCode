//
// Created by Ke Wang on 10/20/24.
//

#ifndef INC_921_MINIMUMADDTOMAKEPARENTHESESVALID_H
#define INC_921_MINIMUMADDTOMAKEPARENTHESESVALID_H

#include "solution.h"

class MinimumAddToMakeParenthesesValid : public solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, cnt = 0;
        for (const char c : s) {
            if (c == '(') {
                ++cnt;
            } else {
                if (cnt > 0) {
                    --cnt;
                } else {
                    ++res;
                }
            }
        }
        return res + cnt;
    }
};

#endif //INC_921_MINIMUMADDTOMAKEPARENTHESESVALID_H
