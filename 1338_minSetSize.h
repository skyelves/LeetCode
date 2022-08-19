//
// Created by 王柯 on 8/18/22.
//

#ifndef LEETCODE_1338_MINSETSIZE_H
#define LEETCODE_1338_MINSETSIZE_H

#include "solution.h"

class MinSetSize : public solution {
public:
    int minSetSize(vector<int>& arr) {
        int res = 0;
        int len = arr.size();
        map<int, int> mm;
        for(auto i : arr) {
            mm[i]++;
        }
        vector<pair<int, int>> myHeap;
        for(auto i : mm) {
            myHeap.push_back({i.second, i.first});
        }
        sort(myHeap.begin(), myHeap.end(), [](auto &left, auto &right) {return left.first > right.first;});
        int tmp = 0;
        for(auto i : myHeap) {
            tmp += i.first;
            res++;
            if (tmp * 2 >= len) {
                break;
            }
        }
        return res;
    }

    void check() {
        vector<int> arr{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
        int res = minSetSize(arr);
        cout << res << endl;
    }
};

#endif //LEETCODE_1338_MINSETSIZE_H
