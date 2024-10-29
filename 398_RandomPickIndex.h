//
// Created by Ke Wang on 10/28/24.
//

#ifndef INC_398_RANDOMPICKINDEX_H
#define INC_398_RANDOMPICKINDEX_H

#include "solution.h"

class RandomPickIndex : public solution {
private:
    unordered_map<int, vector<int>> idx;
public:
    RandomPickIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (idx.find(nums[i]) != idx.end()) {
                idx[nums[i]].push_back(i);
            } else {
                idx[nums[i]] = {i};
            }
        }
    }

    int pick(int target) {
        vector<int> &tmpIdx = idx[target];
        return tmpIdx[rand() % tmpIdx.size()];
    }
};

#endif //INC_398_RANDOMPICKINDEX_H
