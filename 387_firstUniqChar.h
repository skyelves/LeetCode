//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_387_FIRSTUNIQCHAR_H
#define LEETCODE_387_FIRSTUNIQCHAR_H

#include "solution.h"

class FirstUniqChar : public solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int tmp = s[i] - 'a';
            if (cnt[tmp] == -1) {
                cnt[tmp] = i;
            } else {
                cnt[tmp] = -2;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != -2 && cnt[i] != -1) {
                res = min(res, cnt[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

#endif //LEETCODE_387_FIRSTUNIQCHAR_H
