//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_254_GETFACTORS_H
#define LEETCODE_254_GETFACTORS_H

#include "solution.h"

class GetFactors : public solution {
public:
    void dfs(int n, int start, vector<int> tmp, vector<vector<int>> &res) {
        int sqrtN = sqrt(n);
        for (int i = start; i <= sqrtN; ++i) {
            if (n % i == 0) {
                vector<int> newTmp = tmp;
                newTmp.push_back(i);
                dfs(n / i, i, newTmp, res);
                newTmp.push_back(n / i);
                res.push_back(newTmp);
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        dfs(n, 2, {}, res);
        return res;
    }

    void check() {
        int n = 12;
        auto res = getFactors(n);
        for (auto &i : res) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_254_GETFACTORS_H
