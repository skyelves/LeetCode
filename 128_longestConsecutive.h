//
// Created by 王柯 on 8/25/22.
//

#ifndef LEETCODE_128_LONGESTCONSECUTIVE_H
#define LEETCODE_128_LONGESTCONSECUTIVE_H

#include "solution.h"

class LongestConsecutive : public solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        set<int> ss;
        for (auto num : nums) {
            ss.insert(num);
        }
        for (auto num : nums) {
            if (ss.find(num - 1) == ss.end()) {
                int tmp = 1;
                while (ss.find(num + tmp) != ss.end()) {
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }

    void check() {
        vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int res = longestConsecutive(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_128_LONGESTCONSECUTIVE_H
