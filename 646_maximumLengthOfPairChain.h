//
// Created by 王柯 on 8/25/23.
//

#ifndef LEETCODE_646_MAXIMUMLENGTHOFPAIRCHAIN_H
#define LEETCODE_646_MAXIMUMLENGTHOFPAIRCHAIN_H

#include "solution.h"

class MaximumLengthOfPairChain : public solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> cnt(2001, 0);
        for (auto &pair: pairs) {
            int left = pair[0] + 1000, right = pair[1] + 1000;
            cnt[right] = max(cnt[right], 1);
            for (int i = 0; i < left; ++i) {
                cnt[right] = max(cnt[right], cnt[i] + 1);
            }
        }
        int res = 0;
        for (auto &i : cnt) {
            res = max(res, i);
        }

        return res;
    }

    void check() {
        vector<vector<int>> pairs{{-1000, 7}};
        cout << findLongestChain(pairs) << endl;
    }
};

#endif //LEETCODE_646_MAXIMUMLENGTHOFPAIRCHAIN_H
