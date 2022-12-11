//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_121_BESTTIMETOBUYANDSELLSTOCK_H
#define LEETCODE_121_BESTTIMETOBUYANDSELLSTOCK_H

#include "solution.h"

class BestTimeToBuyAndSellStock : public solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int maxPrice = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            res = max(res, maxPrice - prices[i]);
        }

        return res;
    }
};

#endif //LEETCODE_121_BESTTIMETOBUYANDSELLSTOCK_H
