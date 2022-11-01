//
// Created by 王柯 on 11/1/22.
//

#ifndef LEETCODE_1963_MINSWAPS_H
#define LEETCODE_1963_MINSWAPS_H

#include "solution.h"

class MinSwaps : public solution {
public:
    int minSwaps(string s) {
        int res = 0, cnt = 0;
        for (auto &c : s) {
            if (c == '[') {
                ++cnt;
            } else {
                if (cnt == 0) {
                    ++res;
                } else {
                    --cnt;
                }
            }
        }
        return res % 2 == 0 ? res / 2 : res / 2 + 1;
    }
};

#endif //LEETCODE_1963_MINSWAPS_H
