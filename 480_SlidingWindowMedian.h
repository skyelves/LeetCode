//
// Created by Ke Wang on 11/2/24.
//

#ifndef INC_480_SLIDINGWINDOWMEDIAN_H
#define INC_480_SLIDINGWINDOWMEDIAN_H

#include "solution.h"

class SlidingWindowMedian : public solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            vector<double>res(nums.begin(), nums.end());
            return res;
        }
        vector<double> res;
        multiset<int> max_half, min_half;
        for (int i = 0; i < k; ++i) {
            max_half.insert(nums[i]);
        }
        for (int i = 0; i < k / 2; ++i) {
            min_half.insert(*max_half.begin());
            max_half.erase(max_half.begin());
        }
        if (k % 2 == 0) {
            res.push_back(((double)*min_half.rbegin() + *max_half.begin()) / 2);
        } else {
            res.push_back(*max_half.begin());
        }
        for (int i = k; i < nums.size(); ++i) {
            // remove nums[i - k]
            auto iter = max_half.find(nums[i - k]);
            if (iter != max_half.end()) {
                max_half.erase(iter);
                max_half.insert(*min_half.rbegin());
                min_half.erase(prev(min_half.end()));
            } else {
                min_half.erase(min_half.find(nums[i - k]));
            }

            // insert nums[i]
            if (nums[i] > *max_half.begin()) {
                min_half.insert(*max_half.begin());
                max_half.erase(max_half.begin());
                max_half.insert(nums[i]);
            } else {
                min_half.insert(nums[i]);
            }

            if (k % 2 == 0) {
                res.push_back(((double)*min_half.rbegin() + *max_half.begin()) / 2);
            } else {
                res.push_back(*max_half.begin());
            }
        }

        return res;
    }

    void check() override {
        vector<int> nums{6,5,9,5,4,9,1,7,5,5};
        int k = 4;
        auto res = medianSlidingWindow(nums, k);
        for (auto i : res) {
            cout << i << " ";
        }
    }
};

#endif //INC_480_SLIDINGWINDOWMEDIAN_H
