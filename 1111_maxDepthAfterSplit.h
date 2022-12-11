//
// Created by 王柯 on 12/11/22.
//

#ifndef LEETCODE_1111_MAXDEPTHAFTERSPLIT_H
#define LEETCODE_1111_MAXDEPTHAFTERSPLIT_H

#include "solution.h"

class MaxDepthAfterSplit : public solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        int depth1 = 0, depth2 = 0;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                if (depth1 <= depth2) {
                    ++depth1;
                } else {
                    res[i] = 1;
                    ++depth2;
                }
            } else {
                if (depth1 <= depth2) {
                    --depth2;
                    res[i] = 1;
                } else {
                    --depth1;
                }
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_1111_MAXDEPTHAFTERSPLIT_H
