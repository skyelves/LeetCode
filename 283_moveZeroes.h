//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_283_MOVEZEROES_H
#define LEETCODE_283_MOVEZEROES_H

#include "solution.h"

class MoveZeroes : public solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[cnt++] = nums[i];
            }
        }
        for (int i = cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

#endif //LEETCODE_283_MOVEZEROES_H
