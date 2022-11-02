//
// Created by 王柯 on 11/2/22.
//

#ifndef LEETCODE_135_CANDY_H
#define LEETCODE_135_CANDY_H

#include "solution.h"

class Candy : public solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, len = ratings.size();
        vector<int> candy1(len, 0), candy2(len, 0);
        candy1[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy1[i] = candy1[i - 1] + 1;
            } else {
                candy1[i] = 1;
            }
        }
        candy2[len - 1] = 1;
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy2[i] = candy2[i + 1] + 1;
            } else {
                candy2[i] = 1;
            }
        }
        for (int i = 0; i < len; ++i) {
            res += max(candy1[i], candy2[i]);
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_135_CANDY_H
