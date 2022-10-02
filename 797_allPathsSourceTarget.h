//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_797_ALLPATHSSOURCETARGET_H
#define LEETCODE_797_ALLPATHSSOURCETARGET_H

#include "solution.h"

class AllPathsSourceTarget : public solution {
public:
    void dfs(vector<vector<int>> &graph, int curr, vector<int> &path, vector<vector<int>> &res) {
        for (auto i : graph[curr]) {
            path.push_back(i);
            if (i == graph.size() - 1) {
                res.push_back(path);
            } else {
                dfs(graph, i, path, res);
            }
            path.erase(path.end() - 1);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, path, res);

        return res;
    }

    void check() {
        vector<vector<int>> graph{{4, 3, 1},
                                  {3, 2, 4},
                                  {3},
                                  {4},
                                  {}};
        auto res = allPathsSourceTarget(graph);
        for (auto i : res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_797_ALLPATHSSOURCETARGET_H
