//
// Created by 王柯 on 9/8/22.
//

#ifndef LEETCODE_11_MAXAREA_H
#define LEETCODE_11_MAXAREA_H

#include "solution.h"

class MaxArea : public solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0, l = 0, r = height.size() - 1;
        while(l < r) {
            res = max(res, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return res;
    }

    void check() {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int res = maxArea(height);
        cout << res << endl;
    }
};

#endif //LEETCODE_11_MAXAREA_H
