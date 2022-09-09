//
// Created by 王柯 on 9/8/22.
//

#ifndef LEETCODE_11_MAXAREA_H
#define LEETCODE_11_MAXAREA_H

#include "solution.h"

class MaxArea : public solution {
public:
    int calArea(vector<int> &height, int i) {
        int res = 0;
        int h = height[i];
        int len = height.size();
        for (int j = len - 1; j > i; --j) {
            if (height[j] >= h) {
                res += h * (j - i);
                break;
            }
        }
        for (int j = 0; j < i; ++j) {
            if (height[j] >= h) {
                res += h * (i - j);
                break;
            }
        }
        return res;
    }

    int maxArea(vector<int> &height) {
        int res = 0;
        int len = height.size();
        for (int i = 0; i < len; ++i) {
            int tmp = calArea(height, i);
            res = max(res, tmp);
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
