//
// Created by 王柯 on 7/26/22.
//

#ifndef LEETCODE_2248_INTERSECTION_H
#define LEETCODE_2248_INTERSECTION_H

#include "solution.h"

class Intersection : public solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        vector<int> res;
        int array_num = nums.size();
        for (int i = 0; i <= 1000; ++i) {
            bool flag = true;
            for (int j = 0; j < array_num; ++j) {
                if (find(nums[j].begin(), nums[j].end(), i) == nums[j].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(i);
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_2248_INTERSECTION_H
