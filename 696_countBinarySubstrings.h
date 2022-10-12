//
// Created by 王柯 on 10/12/22.
//

#ifndef LEETCODE_696_COUNTBINARYSUBSTRINGS_H
#define LEETCODE_696_COUNTBINARYSUBSTRINGS_H

#include "solution.h"

class CountBinarySubstrings : public solution {
public:
    int countBinarySubstrings(string s) {
        int currCnt = 0, lastCnt = 0, res = 0;
        int idx = 0;
        int currChar = s[0] - '0';
        while (idx < s.size()) {
            currCnt = 0;
            while (idx < s.size() && s[idx] == '0' + currChar) {
                ++idx;
                ++currCnt;
            }
            res += min(currCnt, lastCnt);
            lastCnt = currCnt;
            currChar = 1 - currChar;
        }
        return res;
    }

    void check() {
        string s = "00110011";
        int res = countBinarySubstrings(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_696_COUNTBINARYSUBSTRINGS_H
