//
// Created by 王柯 on 9/12/22.
//

#ifndef LEETCODE_1010_NUMPAIRSDIVISIBLEBY60_H
#define LEETCODE_1010_NUMPAIRSDIVISIBLEBY60_H

#include "solution.h"

class NumPairsDivisibleBy60 : public solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        long long res = 0;
        long long mod60[60] = {0};
        for (auto i : time) {
            mod60[i % 60]++;
        }
//        for (int i = 0; i < 60; ++i) {
//            if (mod60[i] != 0) {
//                cout << i << " " << mod60[i] << endl;
//            }
//        }
        res += mod60[0] * (mod60[0] - 1) / 2 + mod60[30] * (mod60[30] - 1) / 2;
        for (int i = 1; i < 30; ++i) {
            if (mod60[i] != 0)
                res += mod60[i] * mod60[60 - i];
        }
        return (int)res;
    }

    void check() {
        vector<int> time{60, 60, 60, 30, 30};
        int res = numPairsDivisibleBy60(time);
        cout << res << endl;
    }
};

#endif //LEETCODE_1010_NUMPAIRSDIVISIBLEBY60_H
