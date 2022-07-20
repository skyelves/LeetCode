//
// Created by 王柯 on 7/19/22.
//

#ifndef LEETCODE_1021_REMOVEOUTERMOSTPARENTHESES_H
#define LEETCODE_1021_REMOVEOUTERMOSTPARENTHESES_H

#include "solution.h"

class RemoveOuterParentheses : public solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = -1;
        int len = s.size();
        string res;
        for (int i = 0; i < len; ++i) {
            char tmp = s[i];
            if (tmp == '(') {
                cnt += 1;
                if (cnt > 0) {
                    res += tmp;
                }
            } else if (tmp == ')') {
                cnt -= 1;
                if (cnt >= 0) {
                    res += tmp;
                }
            }
        }
        return res;
    }

    void check() {
        string s = "(()())(())";
        string res = removeOuterParentheses(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_1021_REMOVEOUTERMOSTPARENTHESES_H
