//
// Created by Ke Wang on 10/27/24.
//

#ifndef INC_279_PERFECTSQUARES_H
#define INC_279_PERFECTSQUARES_H

#include "solution.h"

class PerfectSquares : public solution {
public:
    int numSquares(int n) {
        vector<int> sum(n + 1, INT32_MAX);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int sqrtI = sqrt(i);
            for (int j = 1; j <= sqrtI; ++j) {
                sum[i] = min(sum[i], sum[i - j * j] + 1);
            }
        }
        return sum[n];
    }
};

#endif //INC_279_PERFECTSQUARES_H
