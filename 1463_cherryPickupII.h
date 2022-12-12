//
// Created by 王柯 on 12/12/22.
//

#ifndef LEETCODE_1463_CHERRYPICKUPII_H
#define LEETCODE_1463_CHERRYPICKUPII_H

#include "solution.h"

class CherryPickupII : public solution {
public:
    int step[3] = {-1, 0, 1};

    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        map<pair<int, int>, int> mm;
        mm[{0, m - 1}] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; ++i) {
            map<pair<int, int>, int> collect;
            for (auto &tmp : mm) {
                for (int j = 0; j < 3; ++j) {
                    int nj1 = tmp.first.first + step[j];
                    if (nj1 < 0 || nj1 >= m) continue;
                    for (int k = 0; k < 3; ++k) {
                        int nj2 = tmp.first.second + step[k];
                        if (nj2 < 0 || nj2 >= m) continue;
                        if (nj1 == nj2) {
                            collect[{nj1, nj2}] = max(collect[{nj1, nj2}], tmp.second + grid[i][nj1]);
                        } else {
                            collect[{nj1, nj2}] = max(collect[{nj1, nj2}], tmp.second + grid[i][nj1] + grid[i][nj2]);
                        }
                    }
                }
            }
            mm = collect;
        }
        for (auto &tmp : mm) {
            res = max(res, tmp.second);
        }

        return res;
    }

    void check() {
        vector<vector<int>> grid{{3, 1, 1},
                                 {2, 5, 1},
                                 {1, 5, 5},
                                 {2, 1, 1}};
        int res = cherryPickup(grid);
        cout << res << endl;
    }
};

#endif //LEETCODE_1463_CHERRYPICKUPII_H
