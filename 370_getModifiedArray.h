//
// Created by 王柯 on 10/7/22.
//

#ifndef LEETCODE_370_GETMODIFIEDARRAY_H
#define LEETCODE_370_GETMODIFIEDARRAY_H

#include "solution.h"

class GetModifiedArray : public solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> num(length + 1, 0), res(length, 0);
        for (auto &update : updates) {
            int s = update[0], e = update[1], n = update[2];
            num[s] += n;
            num[e + 1] -= n;
        }
        res[0] = num[0];
        for (int i = 1; i < length; ++i) {
            res[i] = res[i - 1] + num[i];
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_370_GETMODIFIEDARRAY_H
