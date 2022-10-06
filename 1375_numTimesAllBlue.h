//
// Created by 王柯 on 10/5/22.
//

#ifndef LEETCODE_1375_NUMTIMESALLBLUE_H
#define LEETCODE_1375_NUMTIMESALLBLUE_H

#include "solution.h"

class NumTimesAllBlue : public solution {
public:
    int numTimesAllBlue(vector<int> &flips) {
        vector<bool> flipped(flips.size() + 1, false);
        int res = 0;
        int curr = 1;
        for (int i = 0; i < flips.size(); ++i) {
            flipped[flips[i]] = true;
            if (flips[i] == curr) {
                while (flipped[curr]) {
                    curr++;
                }
                if (curr == i + 2) {
                    res++;
                }
            }
        }
        return res;
    }

    void check() {
        vector<int> flips{4, 1, 2, 3};
        int res = numTimesAllBlue(flips);
        cout << res << endl;
    }
};

#endif //LEETCODE_1375_NUMTIMESALLBLUE_H
