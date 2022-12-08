//
// Created by 王柯 on 12/8/22.
//

#ifndef LEETCODE_277_FINDCELEBRITY_H
#define LEETCODE_277_FINDCELEBRITY_H

#include "solution.h"

/* The knows API is defined for you.
      bool knows(int a, int b); */

class FindCelebrity : public solution {
public:
    vector<vector<int>> graph;

    bool knows(int a, int b) {
        return graph[a][b];
    }

    int findCelebrity(int n) {
        int res = 0, visitedCnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (res != i && !visited[i]) {
                if (knows(res, i)) {
                    visited[res] = true;
                    res = i;
                } else {
                    visited[i] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (res == i) continue;
            if (knows(res, i) || !knows(i, res)) {
                return -1;
            }
        }

        return res;
    }

    void check() {
        graph = {{1, 1, 1},
                 {0, 1, 1},
                 {0, 0, 1}};
        int res = findCelebrity(graph.size());
        cout << res << endl;
    }
};

#endif //LEETCODE_277_FINDCELEBRITY_H
