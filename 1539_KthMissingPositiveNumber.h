//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_1539_KTHMISSINGPOSITIVENUMBER_H
#define LEETCODE_1539_KTHMISSINGPOSITIVENUMBER_H

#include "solution.h"

class KthMissingPositiveNumber : public solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) {
            return k;
        }
        k -= arr[0] - 1;
        for (int i = 1; i < arr.size(); ++i) {
            int res = arr[i - 1] + k;
            k -= arr[i] - arr[i - 1] - 1;
            if (k <= 0) {
                return res;
            }
        }
        return arr[arr.size() - 1] + k;
    }
};

#endif //LEETCODE_1539_KTHMISSINGPOSITIVENUMBER_H
