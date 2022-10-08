//
// Created by 王柯 on 10/7/22.
//

#ifndef LEETCODE_1444_WAYS_H
#define LEETCODE_1444_WAYS_H

#include "solution.h"

class DividePizza : public solution {
public:
    // dp[x][y][k]:
    unordered_map<int, int> mm;
    int **appleNum;
    int len, width;


    int dp(int x, int y, int k, vector<string> &pizza) {
        int key = x * 51 * 51 + y * 51 + k;
        auto iter = mm.find(key);
        if (iter != mm.end()) {
            return iter->second;
        }
        if (k > appleNum[x][y]) {
            mm.insert({key, 0});
            return 0;
        }
        if (k == 1) {
            mm.insert({key, 1});
            return 1;
        }
        int res = 0;
        for (int i = x + 1; i < len; ++i) {
            if (appleNum[x][y] > appleNum[i][y]) {
                res += dp(i, y, k - 1, pizza);
                res %= 1000000000 + 7;
            }
        }
        for (int j = y + 1; j < width; ++j) {
            if (appleNum[x][y] > appleNum[x][j]) {
                res += dp(x, j, k - 1, pizza);
                res %= 1000000000 + 7;
            }
        }
        mm.insert({key, res});
        return res;
    }

    int ways(vector<string> &pizza, int k) {
        len = pizza.size(), width = pizza[0].size();
        appleNum = new int *[len + 1];
        for (int i = 0; i <= len; ++i) {
            appleNum[i] = new int[width + 1];
            memset(appleNum[i], 0, sizeof(int) * (width + 1));
        }
        for (int i = len - 1; i >= 0; --i) {
            for (int j = width - 1; j >= 0; --j) {
                appleNum[i][j] =
                        appleNum[i + 1][j] + appleNum[i][j + 1] - appleNum[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        return dp(0, 0, k, pizza);
    }

    void check() {
        vector<string> pizza{"A..", "AAA", "..."};
        int k = 3;
        int res = ways(pizza, k);
        cout << res << endl;
    }
};


#endif //LEETCODE_1444_WAYS_H
