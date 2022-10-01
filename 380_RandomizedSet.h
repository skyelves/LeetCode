//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_380_RANDOMIZEDSET_H
#define LEETCODE_380_RANDOMIZEDSET_H

#include "solution.h"

class RandomizedSet {
public:
    map<int, int> mm;
    vector<int> vv;

    RandomizedSet() {

    }

    bool insert(int val) {
        auto iter = mm.find(val);
        if (iter != mm.end()) {
            return false;
        } else {
            vv.push_back(val);
            mm.insert({val, vv.size() - 1});
            return true;
        }
    }

    bool remove(int val) {
        auto iter = mm.find(val);
        if (iter != mm.end()) {
            int lastOne = vv[vv.size() - 1];
            mm[lastOne] = iter->second;
            vv[iter->second] = lastOne;
            mm.erase(iter);
            vv.erase(vv.begin() + vv.size() - 1);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {
        return vv[rand() % vv.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#endif //LEETCODE_380_RANDOMIZEDSET_H
