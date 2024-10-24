//
// Created by Ke Wang on 10/24/24.
//

#ifndef INC_2850_MINIMUMMOVESTOSPREADSTONESOVERGRID_H
#define INC_2850_MINIMUMMOVESTOSPREADSTONESOVERGRID_H

#include "solution.h"

class MinimumMovesToSpreadStonesOverGrid : public solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        return dfs(grid);
    }

    int dfs(vector<vector<int>> &grid) {
        int res = INT32_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    ++grid[i][j];
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            if (grid[k][l] > 1) {
                                --grid[k][l];
                                res = min(res, abs(i - k) + abs(j - l) + dfs(grid));
                                ++grid[k][l];
                            }
                        }
                    }
                    --grid[i][j];
                }
            }
        }
        return res == INT32_MAX ? 0 : res;
    }

    void check() {
        vector<vector<int>> grid {{3,2,0},{0,1,0},{0,3,0}};
        cout << minimumMoves(grid);
    }
};

#endif //INC_2850_MINIMUMMOVESTOSPREADSTONESOVERGRID_H
