//
// Created by Ke Wang on 10/29/24.
//

#ifndef INC_1004_MAXCONSECUTIVEONESIII_H
#define INC_1004_MAXCONSECUTIVEONESIII_H

#include "solution.h"

class MaxConsecuritiveOnesIII : public solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, tmp = 0, left = 0, right = 0;
        queue<int> idx;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                if (idx.size() < k) {
                    ++tmp;
                    res = max(res, tmp);
                    idx.push(right);
                } else {
                    if (!idx.empty()) {
                        tmp -= idx.front() - left;
                        left = idx.front() + 1;
                        idx.pop();
                        idx.push(right);
                    } else {
                        tmp = 0;
                        left = right + 1;
                    }
                }
            } else {
                ++tmp;
                res = max(res, tmp);
            }
            ++right;
        }
        return res;
    }
};

#endif //INC_1004_MAXCONSECUTIVEONESIII_H
