//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_274_HINDEX_H
#define LEETCODE_274_HINDEX_H

#include "solution.h"

class HIndex : public solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b) {return a > b;});
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] < i + 1)
                return i;
        }
        return citations.size();
    }

    void check() {

    }
};

#endif //LEETCODE_274_HINDEX_H
