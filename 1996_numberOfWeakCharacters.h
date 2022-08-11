//
// Created by 王柯 on 8/11/22.
//

#ifndef LEETCODE_1996_NUMBEROFWEAKCHARACTERS_H
#define LEETCODE_1996_NUMBEROFWEAKCHARACTERS_H

#include "solution.h"

class NumberOfWeakCharacters : public solution {
public:
    struct sort_order {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] > b[0];
            }
        }
    };

    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        int res = 0;
        sort(properties.begin(), properties.end(), sort_order());
        int prev_max = 0, len = properties.size();
        for (int i = 0; i < len; i++) {
            if (prev_max <= properties[i][1]) {
                prev_max = properties[i][1];
            } else {
                res++;
            }
        }

        return res;
    }

    void check() {
        vector<vector<int>> properties{{2, 2},
                                       {1, 2},
                                       {2, 1},
                                       {1, 1}};
        int res = numberOfWeakCharacters(properties);
        cout << res << endl;
    }
};

#endif //LEETCODE_1996_NUMBEROFWEAKCHARACTERS_H
