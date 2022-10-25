//
// Created by 王柯 on 10/25/22.
//

#ifndef LEETCODE_582_KILLPROCESS_H
#define LEETCODE_582_KILLPROCESS_H

#include "solution.h"

class KillProcess : public solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> res;
        map<int, vector<int>> mm;
        for (int i = 0; i < pid.size(); ++i) {
            mm[ppid[i]].push_back(pid[i]);
        }
        bool visited[50005] = {false};
        queue<int> qq;
        qq.push(kill);
        while(!qq.empty()) {
            int tmp = qq.front();
            res.push_back(tmp);
            qq.pop();
            for (auto i : mm[tmp]) {
                if (!visited[i]) {
                    qq.push(i);
                    visited[i] = true;
                }
            }
        }
        return res;
    }

    void check() {
        vector<int> pid{1, 3, 10, 5}, ppid{3, 0, 5, 3};
        int kill = 5;
        vector<int> res = killProcess(pid, ppid, kill);
        for (auto i : res) {
            cout << i << " ";
        }
    }
};

#endif //LEETCODE_582_KILLPROCESS_H
