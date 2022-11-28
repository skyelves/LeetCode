//
// Created by 王柯 on 11/27/22.
//

#ifndef LEETCODE_22_GENERATEPARENTHESIS_H
#define LEETCODE_22_GENERATEPARENTHESIS_H

#include "solution.h"

class GenerateParenthesis : public solution {
public:
    void dfs(int n, int cnt, string tmp, vector<string> &res) {
        if (cnt == n) {
            if (tmp.size() == 2 * cnt) {
                res.push_back(tmp);
                return;
            }
        } else {
            ++cnt;
            tmp += "(";
            while (tmp.size() < 2 * cnt) {
                dfs(n, cnt, tmp, res);
                tmp += ")";
            }
            dfs(n, cnt, tmp, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, 0, "", res);
        return res;
    }

    void check() {
        auto res = generateParenthesis(3);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_22_GENERATEPARENTHESIS_H
