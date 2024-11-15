//
// Created by Ke Wang on 11/15/24.
//

#ifndef INC_219_CONTAINDUPLICATESII_H
#define INC_219_CONTAINDUPLICATESII_H

#include "solution.h"

class ContainDuplicatesII : public solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (indices.find(tmp) != indices.end()) {
                if (i - indices[tmp] <= k) {
                    return true;
                }
            }
            indices[tmp] = i;
        }
        return false;
    }
};

#endif //INC_219_CONTAINDUPLICATESII_H
