//
// Created by 王柯 on 8/3/22.
//

#ifndef LEETCODE_378_KTHSMALLEST_H
#define LEETCODE_378_KTHSMALLEST_H

#include "solution.h"

class KthSmallest : public solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int len = matrix.size(), width = matrix[0].size();
        multimap<int, pair<int, int>> mm;
        int *visited = new int[len + 1];
        mm.insert({matrix[0][0], {0, 0}});
        memset(visited, 0, sizeof(int) * (len + 1));
        int cnt = 0, res = 0;
        while (cnt < k) {
            auto iter = mm.begin();
            int i = iter->second.first, j = iter->second.second;
            res = iter->first;
            mm.erase(iter);
            cnt++;
            if (i + 1 < len && (visited[i + 1] < j || j == 0)) {
                mm.insert({matrix[i + 1][j], {i + 1, j}});
                visited[i + 1] = j;
            }
            if (j + 1 < width && visited[i] < j + 1) {
                mm.insert({matrix[i][j + 1], {i, j + 1}});
                visited[i] = j + 1;
            }
        }
        return res;
    }

    void check() {
        vector<vector<int>> matrix = {{1,  3,  5},
                                      {6,  7,  12},
                                      {11, 14, 14}};
        int res = kthSmallest(matrix, 9);
        cout << res << endl;
    }
};

#endif //LEETCODE_378_KTHSMALLEST_H
