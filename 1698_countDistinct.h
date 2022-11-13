//
// Created by 王柯 on 11/12/22.
//

#ifndef LEETCODE_1698_COUNTDISTINCT_H
#define LEETCODE_1698_COUNTDISTINCT_H

#include "solution.h"

class CountDistinctSubStrings : public solution {
public:
    int countDistinct(string s) {
        int res = 0, len = s.size();
        vector<vector<int>> trie(len * len, vector<int>(26, 0));
        for (int i = 0; i < len; ++i) {
            int curr = 0;
            for (int j = i; j < len; ++j) {
                int idx = s[j] - 'a';
                if (trie[curr][idx] == 0) {
                    trie[curr][idx] = res;
                    curr = res;
                    ++res;
                } else {
                    curr = trie[curr][idx];
                }
            }
        }
        return res;
    }

    void check() {
        string s = "aabbaba";
        int res = countDistinct(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_1698_COUNTDISTINCT_H
