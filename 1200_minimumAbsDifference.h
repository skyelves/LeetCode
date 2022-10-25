//
// Created by 王柯 on 10/25/22.
//

#ifndef LEETCODE_1200_MINIMUMABSDIFFERENCE_H
#define LEETCODE_1200_MINIMUMABSDIFFERENCE_H

#include "solution.h"

class MinimumAbsDifference : public solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int tmpMin = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            int tmp = arr[i] - arr[i - 1];
            if (tmpMin > tmp) {
                tmpMin = tmp;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            } else if (tmpMin == tmp) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};

#endif //LEETCODE_1200_MINIMUMABSDIFFERENCE_H
