//
// Created by 王柯 on 10/16/22.
//

#ifndef LEETCODE_1614_MAXDEPTH_H
#define LEETCODE_1614_MAXDEPTH_H

#include "solution.h"

class MaxDepth : public solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt = 0;
        for (auto &i : s) {
            if (i == '(') {
                ++cnt;
                res = max(res, cnt);
            } else if (i == ')') {
                --cnt;
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_1614_MAXDEPTH_H
