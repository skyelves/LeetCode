//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_1857_LARGESTPATHVALUE_H
#define LEETCODE_1857_LARGESTPATHVALUE_H

#include "solution.h"

class LargestPathValue : public solution {
public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> mm;
        vector<int> inDegree;
        vector<vector<int>> dp(colors.size(), vector<int>(26, 0));
        int res = 0, cnt = colors.size();
        if (edges.size() == 0) return 1;
        inDegree.resize(colors.size());
        // create graph
        for (auto &edge : edges) {
            int i = edge[0], j = edge[1];
            mm[i].push_back(j);
            ++inDegree[j];
        }
        queue<int> qq;
        for (int i = 0; i < colors.size(); ++i) {
            if (inDegree[i] == 0) {
                qq.push(i);
                --cnt;
            }
        }
        while (!qq.empty()) {
            int tmp = qq.front();
            qq.pop();
            --cnt;
            ++dp[tmp][colors[tmp] - 'a'];
            for (int i = 0; i < 26; ++i) {
                res = max(res, dp[tmp][i]);
            }
            for (auto next : mm[tmp]) {
                for (int i = 0; i < 26; ++i) {
                    dp[next][i] = max(dp[next][i], dp[tmp][i]);
                }
                --inDegree[next];
                if (inDegree[next] == 0) {
                    qq.push(next);
                }
            }
        }
        return cnt == 0 ? res : -1;
    }

    void check() {
        string colors = "abaca";
        vector<vector<int>> edges = {{0, 1},
                                     {0, 2},
                                     {2, 3},
                                     {3, 4}};
        int res = largestPathValue(colors, edges);
        cout << res << endl;
    }
};

#endif //LEETCODE_1857_LARGESTPATHVALUE_H
