//
// Created by 王柯 on 7/25/22.
//

#ifndef LEETCODE_2260_MINIMUMCARDPICKUP_H
#define LEETCODE_2260_MINIMUMCARDPICKUP_H

#include "solution.h"

class MinimumCardPickup : public solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        int tmp_min = 10000000;
        int last_idx[10000000] = {0};
        int len = cards.size();
        for (int i = 0; i < 10000000; ++i) {
            last_idx[i] = -1;
        }
        for (int i = 0; i < len; ++i) {
            int tmp = cards[i];
            if (last_idx[tmp] != -1) {
                int curr = i - last_idx[tmp];
                if (curr < tmp_min) {
                    tmp_min = curr;
                }
            }
            last_idx[tmp] = i;
        }
        return tmp_min == 10000000 ? -1 : tmp_min + 1;
    }

    void check() {

    }
};

#endif //LEETCODE_2260_MINIMUMCARDPICKUP_H
