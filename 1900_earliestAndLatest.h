//
// Created by 王柯 on 12/3/22.
//

#ifndef LEETCODE_1900_EARLIESTANDLATEST_H
#define LEETCODE_1900_EARLIESTANDLATEST_H

#include "solution.h"

class EarliestAndLatest : public solution {
public:
    int earliest = INT_MAX, lastest = 0;

    void dfs(int num, int first, int second, int cnt) {
        // suppose first < second
        if (first + second == num + 1) {
            earliest = min(earliest, cnt);
            lastest = max(lastest, cnt);
            return;
        }
        int newNum = num / 2 + num % 2;
        if (first - 1 < num - second) {
            for (int i = 1; i <= first; ++i) {
                int dis = second - first;
                if (second <= newNum) {
                    for (int j = i + 1; j <= i + dis; ++j) {
                        dfs(newNum, i, j, cnt + 1);
                    }
                } else {
                    for (int j = first - i; j <= num - second - i; ++j) {
                        dfs(newNum, i, newNum - j, cnt + 1);
                    }
                }
            }
        } else {
            dfs(num, num - second + 1, num - first + 1, cnt);
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        earliest = INT_MAX, lastest = 0;
        dfs(n, firstPlayer, secondPlayer, 1);
        return {earliest, lastest};
    }

    void check() {
        auto res = earliestAndLatest(10, 1, 8);
        cout << res[0] << " " << res[1] << endl;
    }
};

#endif //LEETCODE_1900_EARLIESTANDLATEST_H
