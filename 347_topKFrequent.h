//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_347_TOPKFREQUENT_H
#define LEETCODE_347_TOPKFREQUENT_H

#include "solution.h"

class TopKFrequent : public solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        map<int, int> mm;
        for (auto i : nums) {
            ++mm[i];
        }
        vector<pair<int, int>> toSort;
        for (auto i : mm) {
            toSort.push_back(i);
        }
        sort(toSort.begin(), toSort.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });
        for (int i = 0; i < k; ++i) {
            res.push_back(toSort[i].first);
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_347_TOPKFREQUENT_H
