//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_167_TWOSUMII_INPUTARRAYISSORTED_H
#define LEETCODE_167_TWOSUMII_INPUTARRAYISSORTED_H

#include "solution.h"

class TwoSumII : public solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if (numbers[l] + numbers[r] > target) {
                --r;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                break;
            }
        }
        return {l + 1, r + 1};
    }
};

#endif //LEETCODE_167_TWOSUMII_INPUTARRAYISSORTED_H
