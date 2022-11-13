//
// Created by 王柯 on 11/13/22.
//

#ifndef LEETCODE_1823_FINDTHEWINNER_H
#define LEETCODE_1823_FINDTHEWINNER_H

#include "solution.h"

class FindTheWinner : public solution {
public:
    int findTheWinner(int n, int k) {
        list<int> ll;
        for (int i = 1; i <= n; ++i) {
            ll.push_back(i);
        }
        auto iter = ll.begin();

        while (ll.size() > 1) {
            int cnt = 1;
            while (cnt < k) {
                ++iter;
                ++cnt;
                if (iter == ll.end()) {
                    iter = ll.begin();
                }
            }
            cout << *iter << endl;
            ll.erase(iter++);
            if (iter == ll.end())
                iter = ll.begin();
        }
        return *ll.begin();
    }

    void check() {
        int n = 6, k = 5;
        int res = findTheWinner(n, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_1823_FINDTHEWINNER_H
