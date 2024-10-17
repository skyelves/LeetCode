//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_772_BASICCALCULATORIII_H
#define LEETCODE_772_BASICCALCULATORIII_H

#include "solution.h"

class BasicCaculatorIII : public solution {
public:
    int calculate(string s) {
        int  i = 0;
        return cal(s, i);
    }

    int cal(string &s, int &i) {
        int res = 0;
        stack<int> ss;
        int tmp;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                tmp = getNumber(s, i);
                ss.push(tmp);
            } else if (s[i] == '(') {
                ++i;
                ss.push(cal(s, i));
            } else if (s[i] == ')') {
                ++i;
                break;
            } else {
                char tmpOpe = s[i];
                ++i;
                tmp = getNumber(s, i);
                if (tmpOpe == '+') {
                    ss.push(tmp);
                } else if (tmpOpe == '-') {
                    ss.push(tmp * -1);
                } else if (tmpOpe == '*') {
                    tmp *= ss.top();
                    ss.pop();
                    ss.push(tmp);
                } else if (tmpOpe == '/') {
                    tmp = ss.top() / tmp;
                    ss.pop();
                    ss.push(tmp);
                }
            }
        }
        while (!ss.empty()) {
            res += ss.top();
            ss.pop();
        }
        return res;
    }

    int getNumber(string &s, int &i) {
        int res = 0;
        if (s[i] == '(') {
            ++i;
            return cal(s, i);
        }
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            res *= 10;
            res += s[i] - '0';
            ++i;
        }
        return res;
    }

    void check() {
        string s = "2*(5+5*2)/3+(6/2+8)";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_772_BASICCALCULATORIII_H
