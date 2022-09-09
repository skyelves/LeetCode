//
// Created by 王柯 on 9/8/22.
//

#ifndef LEETCODE_122_MAXPROFIT_H
#define LEETCODE_122_MAXPROFIT_H

#include "solution.h"

class MaxProfit : public solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            int tmp = prices[i + 1] - prices[i];
            res += max(tmp, 0);
        }
        return res;
    }

    void check() {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        int res = maxProfit(prices);
        cout << res << endl;
    }
};

#endif //LEETCODE_122_MAXPROFIT_H
