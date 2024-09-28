//
// Created by 王柯 on 10/25/22.
//

#ifndef LEETCODE_20_VALIDPARENTHESES_H
#define LEETCODE_20_VALIDPARENTHESES_H

#include "solution.h"

class ValidParentheses : public solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        map<char, char> close2OpenMap{{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            } else {
                if (!bracketStack.empty() && bracketStack.top() == close2OpenMap[c]) {
                    bracketStack.pop();
                } else {
                    return false;
                }
            }
        }
        return bracketStack.empty();
    }
};

#endif //LEETCODE_20_VALIDPARENTHESES_H
