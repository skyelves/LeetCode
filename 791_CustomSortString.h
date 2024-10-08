//
// Created by Admin on 10/8/2024.
//

#ifndef LEETCODE_791_CUSTOMSORTSTRING_H
#define LEETCODE_791_CUSTOMSORTSTRING_H

#include "solution.h"

class CustomSortString : public solution {
public:
    string customSortString(string order, string s) {
        vector<int> orders(26, INT32_MAX), cnt(26, 0);
        for (int i = 0; i < order.size(); ++i) {
            orders[order[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
        }
        string res = "";
        for (int i = 0; i < order.size(); ++i) {
            string tmp(cnt[order[i] - 'a'], order[i]);
            res += tmp;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0 && orders[i] == INT32_MAX) {
                string tmp(cnt[i], 'a' + i);
                res += tmp;
            }
        }
        return res;
    }
};

#endif //LEETCODE_791_CUSTOMSORTSTRING_H
