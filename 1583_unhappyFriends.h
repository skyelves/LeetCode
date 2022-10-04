//
// Created by 王柯 on 10/3/22.
//

#ifndef LEETCODE_1583_UNHAPPYFRIENDS_H
#define LEETCODE_1583_UNHAPPYFRIENDS_H

#include "solution.h"

class UnhappyFriends : public solution {
public:
    void cntUnhappy(int x, int y, int u, int v, int &res, vector<bool> &visited, vector<vector<int> > &pref_rank) {
        if (pref_rank[x][u] < pref_rank[x][y] && pref_rank[u][x] < pref_rank[u][v]) {
            if (!visited[x]) {
                visited[x] = true;
                res++;
            }
            if (!visited[u]) {
                visited[u] = true;
                res++;
            }
        }
    }

    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
        int res = 0;
        vector<bool> visited(n, false);
        vector<vector<int> > pref_rank(n, vector<int>(n, 0)); // the smaller, the closer
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                pref_rank[i][preferences[i][j]] = j + 1;
            }
        }
        int pairs_num = pairs.size();
        for (int i = 0; i < pairs_num; ++i) {
            int x = pairs[i][0], y = pairs[i][1];
            for (int j = i + 1; j < pairs_num; ++j) {
                int u = pairs[j][0], v = pairs[j][1];
                cntUnhappy(x, y, u, v, res, visited, pref_rank);
                cntUnhappy(x, y, v, u, res, visited, pref_rank);
                cntUnhappy(y, x, u, v, res, visited, pref_rank);
                cntUnhappy(y, x, v, u, res, visited, pref_rank);
            }
        }
        return res;
    }

    void check() {
        int n = 4;
        vector<vector<int>> preferences{{1, 2, 3},
                                        {3, 2, 0},
                                        {3, 1, 0},
                                        {1, 2, 0}}, pairs{{0, 1},
                                                          {2, 3}};
        int res = unhappyFriends(n, preferences, pairs);
        cout << res << endl;
    }
};

#endif //LEETCODE_1583_UNHAPPYFRIENDS_H
