//
// Created by 王柯 on 10/29/22.
//

#ifndef LEETCODE_42_TRAPPINGRAINWATER_H
#define LEETCODE_42_TRAPPINGRAINWATER_H

#include "solution.h"

class TrappingRainWater : public solution {
public:
    int trap(vector<int> &height) {
        /*
         * dp solution
         */
//        int res = 0;
//        vector<int> dp1(height.size(), 0), dp2(height.size(), 0);
//        dp1[0] = height[0];
//        dp2[height.size() - 1] = 0;
//        for (int i = 1; i < height.size(); ++i) {
//            dp1[i] = max(dp1[i - 1], height[i - 1]);
//        }
//        for (int i = height.size() - 2; i >= 0; --i) {
//            dp2[i] = max(dp2[i + 1], height[i + 1]);
//        }
//        for (int i = 1; i < height.size() - 1; ++i) {
//            int tmp = min(dp1[i], dp2[i]) - height[i];
//            if (tmp > 0)
//                res += tmp;
//        }
//        return res;

        /*
        * stack
        */
//        int res = 0;
//        stack<int> ss;
//        int len = height.size();
//        for (int i = 0; i < len; ++i) {
//            while (!ss.empty() && height[ss.top()] < height[i]) {
//                int top = ss.top();
//                ss.pop();
//                if (ss.empty()) break;
//                int dis = i - ss.top() - 1;
//                int diff = min(height[ss.top()], height[i]) - height[top];
//                res += diff * dis;
//            }
//            ss.push(i);
//
//        }
        /*
         * two pointer
         */
        int res = 0;
        int l = 0, r = height.size() - 1;
        int lh = height[l], rh = height[r];
        while (l + 1 < r) {
            if (lh < rh) {
                ++l;
                int diff = lh - height[l];
                if (diff > 0) {
                    res += diff;
                } else {
                    lh = height[l];
                }
            } else {
                --r;
                int diff = rh - height[r];
                if (diff > 0) {
                    res += diff;
                } else {
                    rh = height[r];
                }
            }
        }
        return res;
    }

    void check() {
        vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int res = trap(height);
        cout << res << endl;
    }
};

#endif //LEETCODE_42_TRAPPINGRAINWATER_H
