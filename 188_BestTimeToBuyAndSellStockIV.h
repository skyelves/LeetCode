//
// Created by Ke Wang on 10/25/24.
//

#ifndef INC_188_BESTTIMETOBUYANDSELLSTOCKIV_H
#define INC_188_BESTTIMETOBUYANDSELLSTOCKIV_H

#include "solution.h"

class BestTimeToBuyAndSellStockIV : public solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0, n = prices.size();
        vector<int> buy(k + 1, INT32_MAX), profit(k + 1, 0); // 2 * k states
        buy[1] = prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = min(buy[j], prices[i] - profit[j - 1]);
                profit[j] = max(profit[j], prices[i] - buy[j]);
                res = max(res, profit[j]);
            }
        }
        return res;
    }

    void check() {
        vector<int> prices{3,2,6,5,0,3};
        int k = 2;
        cout << maxProfit(k, prices) << endl;
    }
};

#endif //INC_188_BESTTIMETOBUYANDSELLSTOCKIV_H
