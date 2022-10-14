//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_1857_LARGESTPATHVALUE_H
#define LEETCODE_1857_LARGESTPATHVALUE_H

#include "solution.h"

class LargestPathValue : public solution {
public:
    unordered_map<int, vector<int>> mm;
    vector<int> inDegree;
    int res = 0;

    bool dfs(int curr, map<char, int> &colorMap, set<int> &ss, string &colors) {
        auto iter = mm.find(curr);
        if (iter != mm.end()) {
            for (auto i : iter->second) {
                if (ss.find(i) != ss.end())
                    return true;
                ss.insert(i);
                ++colorMap[colors[i]];
                bool tmp = dfs(i, colorMap, ss, colors);
                ss.erase(i);
                --colorMap[colors[i]];
                if (tmp)
                    return tmp;
            }
        } else {
            for (auto &i : colorMap) {
                res = max(i.second, res);
            }
        }
        return false;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges) {
        res = 0;
        if (edges.size() == 0) return 1;
        inDegree.resize(colors.size());
        // create graph
        for (auto &edge : edges) {
            int i = edge[0], j = edge[1];
            mm[i].push_back(j);
            ++inDegree[j];
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (inDegree[edges[i][0]] == 0) {
                map<char, int> mm;
                set<int> ss;
                ss.insert(edges[i][0]);
                ++mm[colors[edges[i][0]]];
                if (dfs(edges[i][0], mm, ss, colors))
                    return -1;
            }
        }
        return res == 0 ? -1 : res;
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
