//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_636_EXCLUSIVETIME_H
#define LEETCODE_636_EXCLUSIVETIME_H

#include "solution.h"

class ExclusiveTime : public solution {
public:

    int getNum(string &log, int &i) {
        int num = 0;
        while(log[i] >= '0' && log[i] <= '9') {
            num *= 10;
            num += log[i] - '0';
            ++i;
        }
        return num;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n, 0);
        stack<vector<int>> ss;
        for (string &log : logs) {
            int i = 0;
            int id = getNum(log, i);
            i += 1;
            bool isStart = log[i] == 's';
            if (isStart) {
                i += 6;
            } else {
                i += 4;
            }
            int timestamp = getNum(log, i);

            if (isStart) {
                ss.push({id, timestamp, 0});
            } else {
                auto top = ss.top();
                ss.pop();
                res[id] += timestamp - top[1] - top[2] + 1;
                if (!ss.empty()) {
                    auto newTop = ss.top();
                    ss.pop();
                    newTop[2] += timestamp - top[1] + 1;
                    ss.push(newTop);
                }
            }
        }

        return res;
    }

    void check() {
        int n = 2;
        vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
        vector<int> res = exclusiveTime(n, logs);
        for (int i = 0; i < n; ++i) {
            cout << res[i] << endl;
        }
    }
};

#endif //LEETCODE_636_EXCLUSIVETIME_H
