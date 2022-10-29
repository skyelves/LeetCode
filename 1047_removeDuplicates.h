//
// Created by 王柯 on 10/29/22.
//

#ifndef LEETCODE_1047_REMOVEDUPLICATES_H
#define LEETCODE_1047_REMOVEDUPLICATES_H

#include "solution.h"

class RemoveDuplicates : public solution {
public:
    string removeDuplicates(string s) {
        stack<char> ss;
        for (auto &c : s) {
            if (!ss.empty() && c == ss.top()) {
                ss.pop();
            } else {
                ss.push(c);
            }
        }
        string res;
        while (!ss.empty()) {
            res += ss.top();
            ss.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODE_1047_REMOVEDUPLICATES_H
