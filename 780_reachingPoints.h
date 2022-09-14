//
// Created by 王柯 on 9/14/22.
//

#ifndef LEETCODE_780_REACHINGPOINTS_H
#define LEETCODE_780_REACHINGPOINTS_H

#include "solution.h"

class ReachingPoints : public solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) {
                return true;
            }
            if (tx > ty) {
                if (sx >= ty) {
                    if ((tx - sx) % ty == 0 && ty == sy) {
                        return true;
                    } else {
                        return  false;
                    }
                }
                int remainder = tx % ty;
                tx = remainder == 0 ? ty : remainder;
            } else if (tx == ty) {
                tx = 0;
            } else {
                if (sy >= tx) {
                    if ((ty - sy) % tx == 0 && tx == sx) {
                        return true;
                    } else {
                        return  false;
                    }
                }
                int remainder = ty % tx;
                ty = remainder == 0 ? tx : remainder;
            }
        }
        return false;
    }

    void check() {
        int sx = 9, sy = 10, tx = 9, ty = 19;
        bool res = reachingPoints(sx, sy, tx, ty);
        cout << res << endl;
    }

};

#endif //LEETCODE_780_REACHINGPOINTS_H
