//
// Created by 王柯 on 8/3/22.
//

#ifndef LEETCODE_668_FINDKTHNUMBER_H
#define LEETCODE_668_FINDKTHNUMBER_H

#include "solution.h"

class FindKthNumber : public solution {
public:
    int cal(int m, int n, int num) {
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            res += min(n, num / i);
        }
        return res;
    }

    int findKthNumber(int m, int n, int k) {
        int res = 0;
        int left = 1, right = m * n;
        int mid = (left + right) / 2;
        while (left < right) {
            int tmp = cal(m, n, mid);
            if (tmp < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }

    void check() {
        int res = findKthNumber(3, 3, 8);
        cout << res << endl;
    }
};

#endif //LEETCODE_668_FINDKTHNUMBER_H
