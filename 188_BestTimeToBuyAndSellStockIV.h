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
        vector<vector<int>> buy(n, vector<int>(k + 1, INT32_MAX)), profit(n, vector<int>(k + 1, 0));
        buy[0][1] = prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = min(buy[i - 1][j], prices[i] - profit[i - 1][j - 1]);
                profit[i][j] = max(profit[i - 1][j], prices[i] - buy[i][j]);
                res = max(res, profit[i][j]);
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
