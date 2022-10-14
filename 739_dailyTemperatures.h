//
// Created by 王柯 on 10/14/22.
//

#ifndef LEETCODE_739_DAILYTEMPERATURES_H
#define LEETCODE_739_DAILYTEMPERATURES_H

#include "solution.h"

class DailyTemperatures : public solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> temper;
        stack<int> idx;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!temper.empty() && temperatures[i] > temper.top()) {
                res[idx.top()] = i - idx.top();
                idx.pop();
                temper.pop();
            }
            temper.push(temperatures[i]);
            idx.push(i);
        }
        return res;
    }

    void check() {
        vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
        auto res = dailyTemperatures(temperatures);
        for (auto i : res) {
            cout << i << " ";
        }
    }
};

#endif //LEETCODE_739_DAILYTEMPERATURES_H
