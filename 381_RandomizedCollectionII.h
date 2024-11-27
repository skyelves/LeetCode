//
// Created by Ke Wang on 11/26/24.
//

#ifndef INC_381_RANDOMIZEDCOLLECTIONII_H
#define INC_381_RANDOMIZEDCOLLECTIONII_H

#include "solution.h"

class RandomizedCollection : public solution {
    unordered_map<int, unordered_set<int>> mm;
    vector<int> arr;
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        bool res = false;
        if (mm[val].size() == 0) {
            res = true;
        }
        mm[val].insert(arr.size());
        arr.push_back(val);
        return res;
    }

    bool remove(int val) {
        unordered_set<int> &indices = mm[val];
        if (indices.size() == 0) {
            return false;
        }
        int idx = *indices.begin();
        indices.erase(idx);
        if (idx == arr.size() - 1) {
            arr.pop_back();
            return true;
        }
        int lastNum = arr[arr.size() - 1];
        arr[idx] = lastNum;
        arr.pop_back();
        mm[lastNum].erase(arr.size());
        mm[lastNum].insert(idx);

        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};

#endif //INC_381_RANDOMIZEDCOLLECTIONII_H
