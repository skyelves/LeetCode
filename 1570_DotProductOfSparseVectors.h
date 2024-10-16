//
// Created by Admin on 10/15/2024.
//

#ifndef LEETCODE_1570_DOTPRODUCTOFSPARSEVECTORS_H
#define LEETCODE_1570_DOTPRODUCTOFSPARSEVECTORS_H

#include "solution.h"

class SparseVector : public solution {
private:
    unordered_map<int, int> sv;

public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                sv[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (const pair<int, int> &tmp : vec.sv) {
            int i = tmp.first, value = tmp.second;
            if (sv.find(i) != sv.end()) {
                res += sv[i] * value;
            }
        }
        return res;
    }
};

#endif //LEETCODE_1570_DOTPRODUCTOFSPARSEVECTORS_H
