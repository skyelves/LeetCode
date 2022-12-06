//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_772_BASICCALCULATORIII_H
#define LEETCODE_772_BASICCALCULATORIII_H

#include "solution.h"

class BasicCaculatorIII : public solution {
public:
    string infix2suffix(string &s) {
        string res;
        stack<char> ss;
        for (auto &c : s) {
            if (c == ' ') continue;
            if (c == '+' || c == '-') {
                while(!ss.empty() && ss.top() != '(') {
                    res.push_back(' ');
                    res.push_back(ss.top());
                    ss.pop();
                }
                res.push_back(' ');
                ss.push(c);
            } else if (c == '*' || c == '/') {
                while(!ss.empty() && (ss.top() == '*' || ss.top() == '/')) {
                    res.push_back(' ');
                    res.push_back(ss.top());
                    ss.pop();
                }
                res.push_back(' ');
                ss.push(c);
            } else if (c == '(') {
                ss.push(c);
            } else if (c == ')') {
                while(!ss.empty() && ss.top() != '(') {
                    res.push_back(' ');
                    res.push_back(ss.top());
                    ss.pop();
                }
                ss.pop();
            } else {
                //number
                res.push_back(c);
            }
        }
        while(!ss.empty()) {
            res.push_back(' ');
            res.push_back(ss.top());
            ss.pop();
        }

        return res;
    }

    int getNumber(string &s, int &i) {
        int len = s.size(), res = 0;
        while (i < len && s[i] >= '0' && s[i] <= '9') {
            res *= 10;
            res += s[i] - '0';
            ++i;
        }
        return res;
    }

    int calculate(string s) {
        int res = 0;
        s = infix2suffix(s);
        cout << s << endl;
        int len = s.size();
        stack<int> ss;
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int tmp = getNumber(s, i);
                ss.push(tmp);
            } else if (s[i] == '+') {
                int tmp1 = ss.top();
                ss.pop();
                int tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 + tmp1);
            } else if (s[i] == '-') {
                int tmp1 = ss.top();
                ss.pop();
                int tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 - tmp1);
            } else if (s[i] == '*') {
                int tmp1 = ss.top();
                ss.pop();
                int tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 * tmp1);
            } else if (s[i] == '/') {
                int tmp1 = ss.top();
                ss.pop();
                int tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 / tmp1);
            }
        }

        return ss.top();
    }

    void check() {
        string s = "2*(5+5*2)/3+(6/2+8)";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_772_BASICCALCULATORIII_H
