//
// Created by Ke Wang on 11/20/24.
//

#ifndef INC_1424_DIAGONALTRAVERSEII_H
#define INC_1424_DIAGONALTRAVERSEII_H

#include "solution.h"

class DiagonalTraverseII : public solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        int m = 0;
        for (int i = 0; i < nums.size(); ++i) {
            m = max(m, (int)nums[i].size());
        }
        vector<vector<int>> layer(n + m);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                layer[i + j].push_back(nums[i][j]);
            }
        }
        for (int i = 0; i < n + m; ++i) {
            reverse(layer[i].begin(), layer[i].end());
            res.insert(res.end(), layer[i].begin(), layer[i].end());
        }

        return res;
    }

    void check() {
        vector<vector<int>> nums{{1,2,3,4,5,6}};
        auto res = findDiagonalOrder(nums);
        for (auto i : res) {
            cout << i << " ";
        }
    }
};

#endif //INC_1424_DIAGONALTRAVERSEII_H
