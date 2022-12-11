//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_636_EXCLUSIVETIME_H
#define LEETCODE_636_EXCLUSIVETIME_H

#include "solution.h"

class ExclusiveTime : public solution {
public:
    vector<int> split(string &s) {
        // timestamp, id, start
        int id = 0, timestamp = 0, start = 0;
        int idx = s.find(':');
        id = stoi(s.substr(0, idx));
        if (s[idx + 1] == 's') {
            start = 1;
            idx += 7;
        } else {
            start = 0;
            idx += 5;
        }
        timestamp = stoi(s.substr(idx, s.size() - idx));

        return {timestamp, id, start};
    }

    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n, 0);
        vector<vector<int>> l;
        for (auto &log : logs) {
            auto tmp = split(log);
            l.emplace_back(tmp);
        }
        stack<int> ss;
        int lastTime = 0;
        for (int i = 0; i < l.size(); ++i) {
            auto &tmp = l[i];
            if (tmp[2]) {
                if (!ss.empty()) {
                    res[ss.top()] += tmp[0] - lastTime;
                }
                ss.push(tmp[1]);
                lastTime = tmp[0];
            } else {
                res[ss.top()] += tmp[0] - lastTime + 1;
                ss.pop();
                lastTime = tmp[0] + 1;
            }
        }

        return res;
    }

    void check() {
        int n = 3;
        vector<string> logs{"0:start:0", "0:end:0", "1:start:1", "1:end:1", "2:start:2", "2:end:2", "2:start:3",
                            "2:end:3"};
        vector<int> res = exclusiveTime(n, logs);
        for (int i = 0; i < n; ++i) {
            cout << res[i] << endl;
        }
    }
};

#endif //LEETCODE_636_EXCLUSIVETIME_H
