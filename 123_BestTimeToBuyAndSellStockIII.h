//
// Created by Ke Wang on 10/25/24.
//

#ifndef INC_123_BESTTIMETOBUYANDSELLSTOCKIII_H
#define INC_123_BESTTIMETOBUYANDSELLSTOCKIII_H

#include "solution.h"

class BestTimeToBuyAndSellStockIII : public solution {
public:
    int maxProfit(vector<int>& prices) {
        int tmp = 0, n = prices.size(), res = 0;
        vector<int> oneTransProfit1(n, 0), oneTransProfit2(n, 0);
        for (int i = 1; i < n; ++i) {
            tmp += prices[i] - prices[i - 1];
            tmp = tmp < 0 ? 0 : tmp;
            oneTransProfit1[i] = max(oneTransProfit1[i - 1], tmp);
        }
        tmp = 0;
        for (int i = n - 1; i > 0; --i) {
            tmp += prices[i - 1] - prices[i];
            tmp = tmp > 0 ? 0 : tmp;
            oneTransProfit2[i] = min(oneTransProfit2[i - 1], tmp);
        }
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, oneTransProfit1[i] - oneTransProfit2[i + 1]);
        }

        return res;
    }

    void check() {
        vector<int> prices{3,3,5,0,0,3,1,4};
        cout << maxProfit(prices) << endl;
    }
};

#endif //INC_123_BESTTIMETOBUYANDSELLSTOCKIII_H
