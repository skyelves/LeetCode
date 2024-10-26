//
// Created by 王柯 on 10/31/22.
//

#ifndef LEETCODE_301_REMOVEINVALIDPARENTHESES_H
#define LEETCODE_301_REMOVEINVALIDPARENTHESES_H

#include "solution.h"

class RemoveInvalidParentheses : public solution {
    int maxLen = 0;
public:
    void dfs(string &s, int idx, int cnt, string tmp, unordered_set<string> &resS) {
        if (idx == s.size() && cnt == 0) {
            resS.insert(tmp);
            maxLen = max(maxLen, (int)tmp.size());
            return;
        }
        if (cnt < 0 || idx + cnt > s.size() || tmp.size() + s.size() - idx < maxLen) {
            return;
        }
        if (s[idx] == '(') {
            dfs(s, idx + 1, cnt + 1, tmp + "(", resS);
            dfs(s, idx + 1, cnt, tmp, resS);
        } else if (s[idx] == ')') {
            if (cnt > 0) {
                dfs(s, idx + 1, cnt - 1, tmp + ")", resS);
            }
            dfs(s, idx + 1, cnt, tmp, resS);
        } else {
            dfs(s, idx + 1, cnt, tmp + s[idx], resS);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> resS;
        dfs(s, 0, 0, "", resS);
        vector<string> res;
        for (auto &tmp : resS) {
            if (tmp.size() == maxLen) {
                res.push_back(tmp);
            }
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
