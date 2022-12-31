//
// Created by 王柯 on 12/30/22.
//

#ifndef LEETCODE_35_SEARCHINSERT_H
#define LEETCODE_35_SEARCHINSERT_H

#include "solution.h"

class SearchInsert : public solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        return iter - nums.begin();
    }
};

#endif //LEETCODE_35_SEARCHINSERT_H
