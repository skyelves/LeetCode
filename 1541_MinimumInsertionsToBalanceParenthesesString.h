//
// Created by Admin on 9/26/2024.
//

#ifndef LEETCODE_1541_MINIMUMINSERTIONSTOBALANCEPARENTHESESSTRING_H
#define LEETCODE_1541_MINIMUMINSERTIONSTOBALANCEPARENTHESESSTRING_H

#include "solution.h"

class MinimumInsertionsToBalanceParenthesesString : public solution {
public:
    int minInsertions(string s) {
        int rightParentheseCnt = 0;
        int res = 0;
        string newS;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                ++rightParentheseCnt;
                if (rightParentheseCnt % 2 == 0) {
                    newS.push_back(')');
                }
            } else {
                // that is, s[i] = '('
                if (rightParentheseCnt % 2 != 0) {
                    newS.push_back(')');
                    ++res;
                }
                newS.push_back('(');
                rightParentheseCnt = 0;
            }
        }
        if (rightParentheseCnt % 2 != 0) {
            newS.push_back(')');
            ++res;
        }

        int cnt = 0;
        for (int i = 0; i < newS.length(); ++i) {
            if (newS[i] == '(') {
                ++cnt;
            } else {
                --cnt;
            }
            if (cnt < 0) {
                ++cnt;
                ++res;
            }
        }
        if (cnt > 0) {
            res += 2 * cnt;
        }

        return res;
    }

    void check() {
        cout << minInsertions(")))()))))))((()))())))()))))()))()())((()()))()(())()())()()))))))()()((()))(") << endl;
    }
};

#endif //LEETCODE_1541_MINIMUMINSERTIONSTOBALANCEPARENTHESESSTRING_H
