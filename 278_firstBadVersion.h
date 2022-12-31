//
// Created by 王柯 on 12/30/22.
//

#ifndef LEETCODE_278_FIRSTBADVERSION_H
#define LEETCODE_278_FIRSTBADVERSION_H

#include "solution.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class FirstBadVersion : public solution {
public:
    bool isBadVersion(int version);

    int firstBadVersion(int n) {
        long long l = 1, r = n;
        long long res = n;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (isBadVersion(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};

#endif //LEETCODE_278_FIRSTBADVERSION_H
