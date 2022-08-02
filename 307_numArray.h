//
// Created by 王柯 on 7/31/22.
//

#ifndef LEETCODE_307_NUMARRAY_H
#define LEETCODE_307_NUMARRAY_H

#include "solution.h"

class NumArray : public solution {
public:
    int *segment_tree = NULL, *_nums = NULL;
    int segment_tree_len = 0, len = 0;

    void build_tree(int l, int r, int p) {
        if (l > r)
            return;
        if (l == r) {
            segment_tree[p] = _nums[l];
        } else {
            int mid = (l + r) / 2;
            build_tree(l, mid, p * 2);
            build_tree(mid + 1, r, p * 2 + 1);
            segment_tree[p] = segment_tree[p * 2] + segment_tree[p * 2 + 1];
        }
    }

    void update_tree(int l, int r, int p, int index, int diff) {
        if (l > r)
            return;
        segment_tree[p] += diff;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (index > mid) {
            update_tree(mid + 1, r, p * 2 + 1, index, diff);
        } else {
            update_tree(l, mid, p * 2, index, diff);
        }
    }

    int range_query(int l, int r, int p, int left, int right) {
        if (l == r) {
            return segment_tree[p];
        }
        int mid = (l + r) / 2;
        if (l < left) {
            if (left <= mid) {
                if (right <= mid) {
                    return range_query(l, mid, p * 2, left, right);
                } else {
                    int left_sum = range_query(l, mid, p * 2, left, right);
                    int right_sum = range_query(mid + 1, r, p * 2 + 1, left, right);
                    return left_sum + right_sum;
                }
            } else {
                return range_query(mid + 1, r, p * 2 + 1, left, right);
            }
        } else if (r > right) {
            if (right <= mid) {
                return range_query(l, mid, p * 2, left, right);
            } else {
                int left_sum = range_query(l, mid, p * 2, left, right);
                int right_sum = range_query(mid + 1, r, p * 2 + 1, left, right);
                return left_sum + right_sum;
            }
        } else {
            return segment_tree[p];
        }
    }

    NumArray(vector<int> &nums) {
        len = nums.size();
        _nums = new int[len];
        for (int i = 0; i < len; ++i) {
            _nums[i] = nums[i];
        }
        int tmp_len = len;
        segment_tree_len = len;
        while (tmp_len > 0) {
            segment_tree_len *= 2;
            tmp_len /= 2;
        }
        segment_tree = new int[segment_tree_len + 10];
        build_tree(0, len - 1, 1);
    }

    void update(int index, int val) {
        int old_val = _nums[index];
        _nums[index] = val;
        update_tree(0, len - 1, 1, index, val - old_val);
    }

    int sumRange(int left, int right) {
        return range_query(0, len - 1, 1, left, right);
    }

    NumArray() {}

    void init(vector<int> &nums) {
        len = nums.size();
        _nums = new int[len];
        for (int i = 0; i < len; ++i) {
            _nums[i] = nums[i];
        }
        segment_tree = new int[len + 1];
        build_tree(0, len - 1, 1);
    }

    void check() {
        vector<int> nums{1, 5, 3, 5};
        init(nums);
        cout << sumRange(0, 2) << endl;
        update(1, 2);
        cout << sumRange(1, 1) << endl;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

#endif //LEETCODE_307_NUMARRAY_H
