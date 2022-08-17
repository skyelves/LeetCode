//
// Created by 王柯 on 8/16/22.
//

#ifndef LEETCODE_433_MINMUTATION_H
#define LEETCODE_433_MINMUTATION_H

#include "solution.h"

class MinMutation : public solution {
public:
    int **edge;
    int *dis;
    queue<int> qq;

    int minMutation(string start, string end, vector<string> &bank) {
        int wordLen = start.size();
        int res = -1;
        int len = bank.size();
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < len; ++i) {
            if (bank[i] == start) {
                beginIdx = i;
                break;
            }
        }
        if (beginIdx == -1) {
            beginIdx = bank.size();
            bank.push_back(start);
        }
        for (int i = 0; i < len; ++i) {
            if (bank[i] == end) {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -1) {
            return -1;
        }
        len = bank.size();
        dis = new int[len];
        edge = new int *[len];
        for (int i = 0; i < len; ++i) {
            edge[i] = new int[len];
            memset(edge[i], 0, sizeof(int) * len);
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int diffCnt = 0;
                for (int k = 0; k < wordLen; ++k) {
                    if (bank[i][k] != bank[j][k]) {
                        diffCnt++;
                    }
                }
                if (diffCnt == 1) {
                    edge[i][j] = edge[j][i] = 1;
                }
            }
        }

        bool *visited = new bool[len];
        memset(visited, 0, sizeof(bool) * len);
        visited[beginIdx] = true;
        for (int i = 0; i < len; ++i) {
            if (edge[beginIdx][i] == 1) {
                dis[i] = 1;
                qq.push(i);
                visited[i] = true;
            } else {
                dis[i] = INT_MAX;
            }
        }
        bool flag = false;
        while (!qq.empty()) {
            int tmpIdx = qq.front();
            qq.pop();
            if (tmpIdx == endIdx) {
                flag = true;
                break;
            }
            for (int i = 0; i < len; ++i) {
                if (edge[tmpIdx][i] == 1 && !visited[i]) {
                    dis[i] = dis[tmpIdx] + 1;
                    qq.push(i);
                    visited[i] = true;
                }
            }
        }
        if (flag) {
            res = dis[endIdx];
        }

        return res;
    }

    void check() {
        string start = "AAAAACCC", end = "AACCCCCC";
        vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        auto res = minMutation(start, end, bank);
        cout << res << endl;
    }
};

#endif //LEETCODE_433_MINMUTATION_H
