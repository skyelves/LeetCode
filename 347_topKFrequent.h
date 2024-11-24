//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_347_TOPKFREQUENT_H
#define LEETCODE_347_TOPKFREQUENT_H

#include "solution.h"

class TopKFrequent : public solution {
    struct cmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res(k);
        unordered_map<int, int> mm;
        for (auto i : nums) {
            ++mm[i];
        }
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        for (auto &tmp : mm) {
            buckets[tmp.second].push_back(tmp.first);
        }
        int cnt = 0;
        for (int i = nums.size(); i > 0 && cnt < k; --i) {
            if (!buckets[i].empty()) {
                for (int j = 0; j < buckets[i].size() && cnt < k; ++j) {
                    res[cnt] = buckets[i][j];
                    ++cnt;
                }
            }
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_347_TOPKFREQUENT_H
