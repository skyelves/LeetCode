//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_14_LONGESTCOMMONPREFIX_H
#define LEETCODE_14_LONGESTCOMMONPREFIX_H

#include "solution.h"

class LongestCommonPrefix : public solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        int num = strs.size();
        int idx = 0;
        while (1) {
            bool flag = false;
            if (idx >= strs[0].size())
                break;
            char c = strs[0][idx];
            for (int i = 1; i < num; ++i) {
                if (idx >= strs[i].size() || strs[i][idx] != c) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            ++idx;
            res.push_back(c);
        }

        return res;
    }
};

#endif //LEETCODE_14_LONGESTCOMMONPREFIX_H
