//
// Created by 王柯 on 10/31/22.
//

#ifndef LEETCODE_301_REMOVEINVALIDPARENTHESES_H
#define LEETCODE_301_REMOVEINVALIDPARENTHESES_H

#include "solution.h"

class RemoveInvalidParentheses : public solution {
public:
    int maxSize = 0;
    void dfs(int idx, int leftCnt, string &s, string curr, vector<string> &res) {
        if (leftCnt < 0)
            return;
        if (s.size() - idx + curr.size() < maxSize)
            return;
        if (idx == s.size()) {
            if (leftCnt == 0) {
                maxSize = max(maxSize, (int)curr.size());
                res.push_back(curr);
            }
            return;
        }
        if (s[idx] == ')') {
            dfs(idx + 1, leftCnt - 1, s, curr + ")", res);
            dfs(idx + 1, leftCnt, s, curr, res);
        } else if (s[idx] == '(') {
            dfs(idx + 1, leftCnt + 1, s, curr + "(", res);
            dfs(idx + 1, leftCnt, s, curr, res);
        } else {
            dfs(idx + 1, leftCnt, s, curr + s[idx], res);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> tmpRes, res;
        dfs(0, 0, s, "", tmpRes);
        set<string> ss;
        for (auto &i : tmpRes) {
            if (i.size() == maxSize) {
                ss.insert(i);
            }
        }
        for (auto &i : ss){
            res.push_back(i);
        }
        return res;
    }

    void check() {
        string s = "(a)())()";
        auto res = removeInvalidParentheses(s);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_301_REMOVEINVALIDPARENTHESES_H
