//
// Created by Ke Wang on 11/22/24.
//

#ifndef INC_26_REMOVEDUPLICATESFROMSORTEDARRAY_H
#define INC_26_REMOVEDUPLICATESFROMSORTEDARRAY_H

#include "solution.h"

class RemoveDuplicatesFromSortedArray : public solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};

#endif //INC_26_REMOVEDUPLICATESFROMSORTEDARRAY_H
