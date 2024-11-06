//
// Created by Ke Wang on 11/6/24.
//

#ifndef INC_163_MISSINGRANGES_H
#define INC_163_MISSINGRANGES_H

#include "solution.h"

class MissingRanges : public solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return {{lower, upper}};
        }
        vector<vector<int>> res;
        int start = lower;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > start) {
                res.push_back({start, nums[i] - 1});
            }
            start = nums[i] + 1;
        }
        if (start <= upper) {
            res.push_back({start, upper});
        }

        return res;
    }
};

#endif //INC_163_MISSINGRANGES_H
