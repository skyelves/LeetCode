//
// Created by 王柯 on 11/27/22.
//

#ifndef LEETCODE_77_COMBINATIONS_H
#define LEETCODE_77_COMBINATIONS_H

#include "solution.h"

class Combine : public solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        queue<vector<int>> qq;
        qq.push({});
        while (!qq.empty()) {
            auto tmp = qq.front();
            qq.pop();
            int last = tmp.size() != 0 ? tmp.back() : 0;
            int currCnt = tmp.size();
            tmp.push_back(last);
            for (int i = last + 1; i <= (n - k + currCnt + 1); ++i) {
                tmp[currCnt] = i;
                if (currCnt == k - 1) {
                    res.push_back(tmp);
                } else {
                    qq.push(tmp);
                }
            }
        }

        return res;
    }

    void check() {
        auto res = combine(4, 2);
        for (auto &i: res) {
            for (auto &j: i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_77_COMBINATIONS_H
