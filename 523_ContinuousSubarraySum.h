//
// Created by Ke Wang on 10/29/24.
//

#ifndef INC_523_CONTINUOUSSUBARRAYSUM_H
#define INC_523_CONTINUOUSSUBARRAYSUM_H

#include "solution.h"

class ContinuousSubarraySum : public solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        int preSum = 0;
        remainderMap.insert({0, -1});
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];
            preSum %= k;
            if (remainderMap.find(preSum) != remainderMap.end()) {
                if (i - remainderMap[preSum] > 1) {
                    return true;
                }
            } else {
                remainderMap.insert({preSum, i});
            }
        }
        return false;
    }
};

#endif //INC_523_CONTINUOUSSUBARRAYSUM_H
