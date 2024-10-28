//
// Created by Ke Wang on 10/27/24.
//

#ifndef INC_1868_PRODUCTOFTWORUNLENGTHENCODEDARRAY_H
#define INC_1868_PRODUCTOFTWORUNLENGTHENCODEDARRAY_H

#include "solution.h"

class ProductOfTwoRunLengthEncodedArray : public solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res;
        int prev = -1, freq = -1;
        int idx1 = 0, idx2 = 0, cnt1 = encoded1[0][1], cnt2 = encoded2[0][1];
        while (idx1 < encoded1.size() && idx2 < encoded2.size()) {
            int tmp = encoded1[idx1][0] * encoded2[idx2][0];
            int tmpCnt = min(cnt1, cnt2);
            cnt1 -= tmpCnt;
            cnt2 -= tmpCnt;
            if (tmp != prev) {
                if (prev != -1) {
                    res.push_back({prev, freq});
                }
                prev = tmp;
                freq = tmpCnt;
            } else {
                freq += tmpCnt;
            }
            if (cnt1 <= 0) {
                ++idx1;
                if (idx1 >= encoded1.size()) {
                    break;
                }
                cnt1 = encoded1[idx1][1];
            }
            if (cnt2 <= 0) {
                ++idx2;
                if (idx2 >= encoded2.size()) {
                    break;
                }
                cnt2 = encoded2[idx2][1];
            }
        }
        res.push_back({prev, freq});
        return res;
    }

    void check() {
        vector<vector<int>> encoded1{{1,3},{2,3}}, encoded2{{6,3},{3,3}};
        auto res = findRLEArray(encoded1, encoded2);
        for (auto &i : res) {
            for (auto &j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //INC_1868_PRODUCTOFTWORUNLENGTHENCODEDARRAY_H
