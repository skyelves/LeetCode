//
// Created by 王柯 on 12/30/22.
//

#ifndef LEETCODE_896_ISMONOTONIC_H
#define LEETCODE_896_ISMONOTONIC_H

#include "solution.h"

class IsMonotonic : public solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 3) {
            return true;
        }
        bool incr = false, decr = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                incr = true;
            else if (nums[i] < nums[i - 1])
                decr = true;
        }
        return incr ^ decr;
    }
};

#endif //LEETCODE_896_ISMONOTONIC_H
