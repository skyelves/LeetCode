//
// Created by 王柯 on 11/1/22.
//

#ifndef LEETCODE_656_CHEAPESTJUMP_H
#define LEETCODE_656_CHEAPESTJUMP_H

#include "solution.h"

class CheapestJump : public solution {
public:
    vector<int> cheapestJump(vector<int> &coins, int maxJump) {
        vector<int> res;
        int len = coins.size();
        vector<int> dp(len + 1, 10000000), path(len + 1, -1);
        dp[0] = coins[0];
        for (int i = 1; i < len; ++i) {
            if (coins[i] == -1) continue;
            for (int j = 1; j <= min(i, maxJump); ++j) {
                if (coins[i - j] == -1 || dp[i - j] == 10000000) continue;
                int tmp = dp[i - j] + coins[i];
                if (dp[i] > tmp) {
                    dp[i] = tmp;
                    path[i] = i - j;
                }
            }
        }
        if (dp[len - 1] == 10000000) return res;
        queue<vector<int>> qq;
        qq.push({len - 1});
        while (!qq.empty()) {
            auto tmp = qq.front();
            qq.pop();
            if (tmp.back() == 0) {
                reverse(tmp.begin(), tmp.end());
                if (res.size() == 0) {
                    res = tmp;
                } else {
                    int flag = -1;
                    for (int i = 0; i < min(res.size(), tmp.size()); ++i) {
                        if (res[i] == tmp[i]) continue;
                        if (res[i] > tmp[i]) {
                            flag = 1;
                            break;
                        } else {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1) {
                        res = tmp;
                    } else if (flag == -1) {
                        if (res.size() < tmp.size())
                            res = tmp;
                    }
                }
            } else {
                int lastOne = tmp.back();
                for (int i = path[lastOne]; i >= max(lastOne - maxJump, 0); --i) {
                    if (dp[i] == dp[path[lastOne]]) {
                        vector<int> newQ = tmp;
                        newQ.push_back(i);
                        qq.push(newQ);
                    }
                }
            }
        }
        for (auto &i: res) {
            ++i;
        }
        return res;
    }

    void check() {
        vector<int> coins{0, 0, 0, 0, 0, 0};
        int maxJump = 3;
        vector<int> res = cheapestJump(coins, maxJump);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_656_CHEAPESTJUMP_H
