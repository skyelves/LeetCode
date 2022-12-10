//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_528_RANDOMPICKWITHWEIGHT_H
#define LEETCODE_528_RANDOMPICKWITHWEIGHT_H

#include "solution.h"

class RandomPickWithWeight : public solution {
public:
    int sum = 0;
    vector<int> _w;

    RandomPickWithWeight(vector<int>& w) {
        _w.resize(w.size());
        _w[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            _w[i] = _w[i - 1] + w[i];
        }
        sum = _w[w.size() - 1];
    }

    int pickIndex() {
        int hashValue = rand() % sum;
        return upper_bound(_w.begin(), _w.end(), hashValue) - _w.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

#endif //LEETCODE_528_RANDOMPICKWITHWEIGHT_H
