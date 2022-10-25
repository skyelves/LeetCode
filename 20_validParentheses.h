//
// Created by 王柯 on 10/25/22.
//

#ifndef LEETCODE_20_VALIDPARENTHESES_H
#define LEETCODE_20_VALIDPARENTHESES_H

#include "solution.h"

class ValidParentheses : public solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto &c : s) {
            if (c == ')') {
                if (!ss.empty() && ss.top() == '(') {
                    ss.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!ss.empty() && ss.top() == '[') {
                    ss.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!ss.empty() && ss.top() == '{') {
                    ss.pop();
                } else {
                    return false;
                }
            } else {
                ss.push(c);
            }
        }
        return ss.empty();
    }
};

#endif //LEETCODE_20_VALIDPARENTHESES_H
