//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_315_COUNTSMALLER_H
#define LEETCODE_315_COUNTSMALLER_H

#include "solution.h"

class CountSmaller : public solution {
    vector<int> segmentTree;
public:
    void incrSegmentTree(int node, int l, int r, int idx) {
        if (l == r) {
            // leaf node
            ++segmentTree[node];
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) {
                incrSegmentTree(node * 2, l, mid, idx);
            } else {
                incrSegmentTree(node * 2 + 1, mid + 1, r, idx);
            }
            ++segmentTree[node];
        }
    }

    int RangeQuery(int node, int l, int r, int start, int end) {
        // [0, idx)
        int res = 0;
        if (l > end || r < start)
            return 0;
        if (start <= l && end >= r) {
            return segmentTree[node];
        }
        int mid = (l + r) / 2;
        int q1 = RangeQuery(node * 2, l, mid, start, end);
        int q2 = RangeQuery(node * 2 + 1, mid + 1, r, start, end);
        return q1 + q2;
    }

    vector<int> countSmaller(vector<int> &nums) {
        segmentTree.resize(200000, 0);
        vector<int> res;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            // shift num to non-negative
            res.push_back(RangeQuery(1, 0, 20000, 0, nums[i] + 10000 - 1));
            incrSegmentTree(1, 0, 20000, nums[i] + 10000);
        }
        reverse(res.begin(), res.end());

        return res;
    }

    void check() {
        vector<int> nums{5, 2, 6, 1};
        auto res = countSmaller(nums);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_315_COUNTSMALLER_H
