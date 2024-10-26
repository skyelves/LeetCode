//
// Created by Ke Wang on 10/25/24.
//

#ifndef INC_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
#define INC_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H

#include "solution.h"

class BestTimeToBuyAndSellStockWithCooldown : public solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], cool = 0, profit = 0;
        for (int i = 1; i < n; ++i) {
            int prevCool = cool;
            cool = max(cool, prices[i] - buy);
            buy = min(buy, prices[i] - profit);
            profit = prevCool;
        }

        return max(cool, profit);
    }
};

#endif //INC_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
