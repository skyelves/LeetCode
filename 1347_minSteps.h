//
// Created by 王柯 on 10/23/22.
//

#ifndef LEETCODE_1347_MINSTEPS_H
#define LEETCODE_1347_MINSTEPS_H

#include "solution.h"

class MinSteps : public solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            ++cnt1[s[i] - 'a'];
            ++cnt2[t[i] - 'a'];
        }
        int dis = 0;
        for (int i = 0; i < 26; ++i) {
            dis += abs(cnt1[i] - cnt2[i]);
        }
        return dis / 2;
    }
};

#endif //LEETCODE_1347_MINSTEPS_H
