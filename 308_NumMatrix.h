//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_308_NUMMATRIX_H
#define LEETCODE_308_NUMMATRIX_H

#include "solution.h"

class NumMatrix : public solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> bit;
    int len = 0, width = 0;

    inline int lsb(int n) {
        return n & -n;
    }

    inline int findParent(int n) {
        return n + lsb(n);
    }

    void updateBit(int r, int c, int diff) {
        for (int i = r; i <= len; i = findParent(i)) {
            for (int j = c; j <= width; j = findParent(j)) {
                bit[i][j] += diff;
            }
        }
    }

    int queryBit(int r, int c) {
        int res = 0;
        for (int i = r; i > 0; i -= lsb(i)) {
            for (int j = c; j > 0; j -= lsb(j)) {
                res += bit[i][j];
            }
        }
        return res;
    }

    void buildBit() {
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= width; ++j) {
                updateBit(i, j, mat[i - 1][j - 1]);
            }
        }
    }

    NumMatrix(vector<vector<int>> &matrix) {
        mat = matrix;
        len = matrix.size();
        if (len > 0)
            width = matrix[0].size();
        bit = vector<vector<int>>(len + 1, vector<int>(width + 1));
        buildBit();
    }

    void update(int row, int col, int val) {
        updateBit(row + 1, col + 1, val - mat[row][col]);
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        int sum1 = queryBit(row2, col2), sum2 = queryBit(row2, col1 - 1), sum3 = queryBit(row1 - 1,
                                                                                          col2), sum4 = queryBit(
                row1 - 1,
                col1 - 1);
        return sum1 - sum2 - (sum3 - sum4);
    }


    NumMatrix() {}

    void init(vector<vector<int>> &matrix) {
        mat = matrix;
        len = matrix.size();
        if (len > 0)
            width = matrix[0].size();
        bit = vector<vector<int>>(len + 1, vector<int>(width + 1));
        buildBit();
    }

    void check() {
        vector<vector<int>> matrix{{2,  4},
                                   {-3, 5}};
        init(matrix);
        int res1 = sumRegion(0, 0, 1, 1);
        update(0, 1, 3);
        int res2 = sumRegion(0, 0, 1, 1);
        update(1, 1, -3);
        int res3 = sumRegion(0, 0, 1, 1);
        update(0, 1, 1);
        int res4 = sumRegion(0, 0, 1, 1);
        cout << res1 << endl << res2 << endl << res3 << endl << res4 << endl;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

#endif //LEETCODE_308_NUMMATRIX_H
