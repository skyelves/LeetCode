//
// Created by Ke Wang on 11/22/24.
//

#ifndef INC_80_REMOVEDUPLICATESFROMSORTEDARRAYII_H
#define INC_80_REMOVEDUPLICATESFROMSORTEDARRAYII_H

#include "solution.h"

class RemoveDuplicatesFromSortedArrayII : public solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++cnt;
                if (cnt <= 2) {
                    nums[j] = nums[i];
                    ++j;
                }
            } else {
                nums[j] = nums[i];
                ++j;
                cnt = 1;
            }
        }
        return j;
    }
};

#endif //INC_80_REMOVEDUPLICATESFROMSORTEDARRAYII_H
