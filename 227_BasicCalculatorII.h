//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_227_BASICCALCULATORII_H
#define LEETCODE_227_BASICCALCULATORII_H

#include "solution.h"

class BasicCalculatorII : public solution {
public:
    string infix2Suffix(string s) {
        stack<char> ss;
        string res;
        for (auto &c : s) {
            if (c == '+' || c == '-') {
                while(!ss.empty()) {
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
            } else {
                if (c != ' ') {
                    // number
                    res.push_back(c);
                }
            }
        }
        while (!ss.empty()) {
            res.push_back(' ');
            res.push_back(ss.top());
            ss.pop();
        }

        return res;
    }

    int calculate(string s) {
        s = infix2Suffix(s);
        cout << s << endl;
        stack<int> ss;
        int tmp1 = 0, tmp2 = 0;
        bool toPush = false;
        for (auto &c : s) {
            if (c == '+') {
                tmp1 = ss.top();
                ss.pop();
                tmp2 = ss.top();
                ss.pop();
                ss.push(tmp1 + tmp2);
                tmp1 = 0;
            } else if (c == '-') {
                tmp1 = ss.top();
                ss.pop();
                tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 - tmp1);
                tmp1 = 0;
            } else if (c == '*') {
                tmp1 = ss.top();
                ss.pop();
                tmp2 = ss.top();
                ss.pop();
                ss.push(tmp1 * tmp2);
                tmp1 = 0;
            } else if (c == '/') {
                tmp1 = ss.top();
                ss.pop();
                tmp2 = ss.top();
                ss.pop();
                ss.push(tmp2 / tmp1);
                tmp1 = 0;
            } else if (c == ' ') {
                if (toPush) {
                    ss.push(tmp1);
                    toPush = false;
                    tmp1 = 0;
                }
            } else {
                toPush = true;
                tmp1 *= 10;
                tmp1 += c - '0';
            }
        }

        return ss.empty() ? tmp1 : tmp1 + ss.top();
    }

    void check() {
        string s = "14/3*2";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_227_BASICCALCULATORII_H
