//
// Created by Ke Wang on 10/27/24.
//

#ifndef INC_1331_RANKTRANSFORMOFANARRAY_H
#define INC_1331_RANKTRANSFORMOFANARRAY_H

#include "solution.h"

class RankTransformOfAnArray : public solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy(arr.begin(), arr.end());
        sort(copy.begin(), copy.end());
        int rank = 1, prev = INT32_MIN;
        unordered_map<int, int> rankMap;
        for (int i = 0; i < copy.size(); ++i) {
            if (copy[i] != prev) {
                rankMap[copy[i]] = rank;
                ++rank;
                prev = copy[i];
            }
        }
        vector<int> res(arr.size(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            res[i] = rankMap[arr[i]];
        }
        return res;
    }
};

#endif //INC_1331_RANKTRANSFORMOFANARRAY_H
