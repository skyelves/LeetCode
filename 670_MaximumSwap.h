//
// Created by Admin on 10/4/2024.
//

#ifndef LEETCODE_670_MAXIMUMSWAP_H
#define LEETCODE_670_MAXIMUMSWAP_H

#include "solution.h"

class MaximumSwap : public solution {
public:
    int maximumSwap(int num) {
        vector<int8_t> idx(10, -1), numVector;
        int cnt = 0;
        while (num != 0) {
            int8_t tmp = num % 10;
            numVector.push_back(tmp);
            if (idx[tmp] == -1) {
                idx[tmp] = cnt;
            }
            num /= 10;
            ++cnt;
        }

        bool swap = false;
        for (int i = numVector.size() - 1; i >= 0; --i) {
            for (int j = 9; j > numVector[i]; --j) {
                if (idx[j] > -1 && idx[j] < i) {
                    numVector[idx[j]] = numVector[i];
                    numVector[i] = j;
                    swap = true;
                    break;
                }
            }
            if (swap) {
                break;
            }
        }

        int res = 0;
        for (int i = numVector.size() - 1; i >= 0; --i) {
            res *= 10;
            res += numVector[i];
        }
        return res;
    }
};

#endif //LEETCODE_670_MAXIMUMSWAP_H
