//
// Created by Ke Wang on 11/19/24.
//

#ifndef INC_658_FINDKCLOSESTELEMENTS_H
#define INC_658_FINDKCLOSESTELEMENTS_H

#include "solution.h"

class FindKClosestElements : public solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto idx1 = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        auto idx2 = idx1;
        if (idx1 == 0) {
            ++idx2;
        } else {
            --idx1;
        }
        int cnt = 0;
        vector<int> res(k, 0);
        while(cnt < k) {
            if (idx1 >= 0 && idx2 < arr.size()) {
                if (abs(arr[idx1] - x) <= abs(arr[idx2] - x)) {
                    res[cnt] = arr[idx1];
                    --idx1;
                } else {
                    res[cnt] = arr[idx2];
                    ++idx2;
                }
            } else if (idx1 < 0) {
                res[cnt] = arr[idx2];
                ++idx2;
            } else if (idx2 >= arr.size()) {
                res[cnt] = arr[idx1];
                --idx1;
            }
            ++cnt;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

#endif //INC_658_FINDKCLOSESTELEMENTS_H
