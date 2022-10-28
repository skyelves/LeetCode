//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_964_LEASTOPSEXPRESSTARGET_H
#define LEETCODE_964_LEASTOPSEXPRESSTARGET_H

#include "solution.h"

class LeastOpsExpressTarget : public solution {
public:
    map<int, int> mm;

    int leastOpsExpressTarget(int x, int target) {
        if (mm.find(target) != mm.end())
            return mm[target];
        if (target == x) {
            mm[x] = 0;
            return 0;
        } else if (target == 1) {
            mm[1] = 1;
            return 1;
        }
        int res = 0;
        if (target < x) {
            res = min(target * 2 - 1, (x - target) * 2);
            mm[target] = res;
            return res;
        }
        long tmp = x;
        int cnt = 0;
        while (tmp * x < target) {
            tmp *= x;
            ++cnt;
        }
        res = cnt + 1 + leastOpsExpressTarget(x, target - tmp);
        if (tmp * x < target * 2) {
            res = min(cnt + 2 + leastOpsExpressTarget(x, tmp * x - target), res);
        }
        mm[target] = res;
        return res;
    }

    void check() {
        int x = 3, target = 19;
        int res = leastOpsExpressTarget(x, target);
        cout << res << endl;
    }
};

#endif //LEETCODE_964_LEASTOPSEXPRESSTARGET_H
